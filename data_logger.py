import argparse
import csv
import os
import time

import serial

# --- CONFIGURATION ---
# Set via --port or SIA_SERIAL_PORT (e.g., /dev/ttyUSB0 on macOS/Linux)
SERIAL_PORT = os.getenv("SIA_SERIAL_PORT", "COM3")
BAUD_RATE = 115200
FILE_NAME = "raw_sensor_data.csv"
FLUSH_EVERY_ROWS = 20
FLUSH_INTERVAL_SECONDS = 2.0
CSV_HEADER = ["Temperature", "Humidity", "Methane"]  # Raw logging only; labels are added later for model-training datasets


def parse_sensor_line(line: str):
    payload = line
    if line.startswith("Data:"):
        payload = line.split(":", 1)[1].strip()

    parts = [part.strip() for part in payload.split(",")]
    if len(parts) != 3:
        return None

    values = []
    for part in parts:
        if "=" in part:
            _, value = part.split("=", 1)
            values.append(value.strip())
        else:
            values.append(part)

    try:
        temperature = float(values[0])
        humidity = float(values[1])
        try:
            methane = int(values[2])
        except ValueError:
            methane = int(float(values[2]))
    except ValueError:
        return None

    return [temperature, humidity, methane]


def parse_args():
    parser = argparse.ArgumentParser(description="Log compost sensor data from serial to CSV.")
    parser.add_argument("--port", default=SERIAL_PORT, help="Serial port (or set SIA_SERIAL_PORT)")
    parser.add_argument("--baud-rate", type=int, default=BAUD_RATE, help="Serial baud rate")
    parser.add_argument("--output", default=FILE_NAME, help="CSV output path")
    return parser.parse_args()

def main():
    args = parse_args()

    try:
        # Connect to ESP32
        ser = serial.Serial(args.port, args.baud_rate, timeout=1)
        time.sleep(2)  # Wait for connection to stabilize
        print(f"Connected to {args.port}. Logging to {args.output}...")

        try:
            file_is_new_or_empty = os.path.getsize(args.output) == 0
        except OSError:
            file_is_new_or_empty = True

        with open(args.output, mode='a', newline='') as file:
            writer = csv.writer(file)
            pending_rows = 0
            last_flush = time.monotonic()
            
            # If the file is new/empty, add the header expected by training scripts
            if file_is_new_or_empty:
                writer.writerow(CSV_HEADER)

            while True:
                raw = ser.readline()
                if not raw:
                    continue

                line = raw.decode('utf-8', errors='ignore').strip()
                if not line:
                    continue

                data = parse_sensor_line(line)
                if data is not None:  # Temp, Hum, Methane
                    print(f"Received: {data}")
                    writer.writerow(data)
                    pending_rows += 1

                now = time.monotonic()
                if pending_rows >= FLUSH_EVERY_ROWS or (now - last_flush) >= FLUSH_INTERVAL_SECONDS:
                    file.flush()
                    pending_rows = 0
                    last_flush = now

    except KeyboardInterrupt:
        print("\nLogging stopped by user.")
    except serial.SerialException as e:
        print(f"Serial port error: {e}")
    except OSError as e:
        print(f"File I/O error: {e}")
    finally:
        if 'ser' in locals():
            ser.close()

if __name__ == "__main__":
    main()

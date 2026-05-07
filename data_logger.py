import serial
import csv
import time

# --- CONFIGURATION ---
# Change 'COM3' to your actual port (e.g., '/dev/ttyUSB0' on Mac/Linux)
# You can see the port name at the bottom of VS Code
SERIAL_PORT = 'COM3' 
BAUD_RATE = 115200
FILE_NAME = "compost_data.csv"
FLUSH_EVERY_ROWS = 20
FLUSH_INTERVAL_SECONDS = 2.0

def main():
    try:
        # Connect to ESP32
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        time.sleep(2)  # Wait for connection to stabilize
        print(f"Connected to {SERIAL_PORT}. Logging to {FILE_NAME}...")

        with open(FILE_NAME, mode='a', newline='') as file:
            writer = csv.writer(file)
            pending_rows = 0
            last_flush = time.monotonic()
            
            # If the file is new, add the header
            # writer.writerow(["Temperature", "Humidity", "Methane", "Label"])

            while True:
                raw = ser.readline()
                if not raw:
                    continue

                line = raw.decode('utf-8', errors='ignore').strip()
                if not line:
                    continue

                data = [value.strip() for value in line.split(',')]
                if len(data) == 3:  # Temp, Hum, Methane
                    # For now, we will print it.
                    # Later we will add the "Label" manually.
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
    except Exception as e:
        print(f"Error: {e}")
    finally:
        if 'ser' in locals():
            ser.close()

if __name__ == "__main__":
    main()

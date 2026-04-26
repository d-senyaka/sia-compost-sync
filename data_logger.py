import serial
import csv
import time

# --- CONFIGURATION ---
# Change 'COM3' to your actual port (e.g., '/dev/ttyUSB0' on Mac/Linux)
# You can see the port name at the bottom of VS Code
SERIAL_PORT = 'COM3' 
BAUD_RATE = 115200
FILE_NAME = "compost_data.csv"

def main():
    try:
        # Connect to ESP32
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        time.sleep(2)  # Wait for connection to stabilize
        print(f"Connected to {SERIAL_PORT}. Logging to {FILE_NAME}...")

        with open(FILE_NAME, mode='a', newline='') as file:
            writer = csv.writer(file)
            
            # If the file is new, add the header
            # writer.writerow(["Temperature", "Humidity", "Methane", "Label"])

            while True:
                if ser.in_waiting > 0:
                    line = ser.readline().decode('utf-8').strip()
                    if line:
                        data = line.split(',')
                        if len(data) == 3:  # Temp, Hum, Methane
                            # For now, we will print it. 
                            # Later we will add the "Label" manually.
                            print(f"Received: {data}")
                            writer.writerow(data)
                            file.flush() # Save to disk immediately

    except KeyboardInterrupt:
        print("\nLogging stopped by user.")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        if 'ser' in locals():
            ser.close()

if __name__ == "__main__":
    main()
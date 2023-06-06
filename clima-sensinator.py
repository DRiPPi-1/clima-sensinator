import serial

# Specify the serial port and baud rate
serial_port = 'COM3'  # Replace 'COM3' with the appropriate port
baud_rate = 9600

# Open the serial port
ser = serial.Serial(serial_port, baud_rate)

# Open the file in write mode
file_path = 'sensor_data.txt'
file = open(file_path, 'w')

while True:
    # Read a line of data from the serial port
    line = ser.readline().decode('utf-8').strip()

    # Print the received line to the console
    print(line)

    # Write the received line to the file
    file.write(line + '\n')

    # If you want to stop receiving data and close the file, press Ctrl+C in the terminal

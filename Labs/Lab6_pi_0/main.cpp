#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	// argc is the number of command-line arguments provided to the program.
	// The first argument (argv[0]) is always the name of the program.
	if (argc < 3) {
		printf("Usage:\n");
		printf("%s /dev/ttyXXX r\tToggle RED\n", argv[0]);
		printf("%s /dev/ttyXXX g\tToggle GREEN\n", argv[0]);
		printf("%s /dev/ttyXXX b\tToggle BLUE\n", argv[0]);
		return 1;
	}

	// Open the serial port for reading and writing.
	// Returns a file descriptor that can be used with standard Linux functions
	// read and write. See:
	//     $ man 2 read
	//     $ man 2 write
	int serial_port = open(argv[1], O_RDWR | O_NONBLOCK);

	// Configure the serial port
	termios tio; // termios is a struct defined in termios.h
	memset(&tio, 0, sizeof(termios)); // Zero out the tio structure
	tio.c_cflag = CS8; // Select 8 data bits
	cfsetospeed(&tio, B9600); // baud rate for output
	cfsetispeed(&tio, B9600); // baud rate for input
	tcsetattr(serial_port, TCSANOW, &tio); // Apply these settings

	// Send the first char of argv[2] over the serial port
	printf("TODO: Send %s over the serial port\n", argv[2]);

	int size_write = write(serial_port, argv[2], 1);

		if (size_write < 0) {
			// Error. Abort.
			printf("Failed to read from the serial port:\n");
			//printf("%s\n", strerror(errno));
			return 1;
		}

	// The code below demonstrates how to receive a single character.
	printf("Waiting for a character to be received ...\n");
	char c;
	int bytes_read;
	// Read a single character. Keep trying until a char is received.
	do {
		bytes_read = read(serial_port, &c, 1);

		if (bytes_read < 0) {
			// Error. Abort.
			printf("Failed to read from the serial port:\n");
			printf("%s\n", strerror(errno));
			return 1;
		}
	if (bytes_read != 0){
	//continue;
	printf("%c",c);
	}
	} while ( c!=0x0A);

	// Echo the character
	// printf("%c\n", c); // %c means print a single char
	printf("\n");

	// Exit
	return 0;
}

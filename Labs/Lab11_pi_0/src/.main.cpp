#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <curl/curl.h>

#define BUF_SIZE 100

int main(int argc, char *argv[])
	//const char * urlp1= "https://data.sparkfun.com/input/dZqnXrRJZOT5Oq8yjoy5?private_key=eEVnrkG1EMu8NDmxVrx8&";
{
    // argc is the number of command-line arguments provided to the program.
    // The first argument (argv[0]) is always the name of the program.
    if (argc < 2) {
        printf("Usage:\n");
        printf("%s /dev/ttyXXX Receive data sent over the specified serial port\n", argv[0]);
        return 1;
    }

    // Open the serial port for reading and writing.
    // Returns a file descriptor that can be used with standard Linux functions
    // read and write. See:
    //     $ man 2 read
    //     $ man 2 write
    int serial_port = open(argv[1], O_RDWR); // Blocking I/O

    // Configure the serial port
    termios tio; // termios is a struct defined in termios.h
    memset(&tio, 0, sizeof(termios)); // Zero out the tio structure
    tio.c_cflag = CS8|CLOCAL|CREAD; // Select 8 data bits
    tio.c_cc[VMIN] = 1; // Always return at least one character
    cfsetospeed(&tio, B9600); // baud rate for output
    cfsetispeed(&tio, B9600); // baud rate for input
    tcsetattr(serial_port, TCSANOW, &tio); // Apply these settings

    // Read from the serial port
    char buf [BUF_SIZE];
	char url2 [BUF_SIZE];
    int buf_idx = 0; // index of first empty item

    for (;;) {
        // Read one byte (blocking)
        char c;

        size_t bytes_read = read(serial_port, &c, 1);
        if (bytes_read == 0) {
            continue;
        } else if (bytes_read != 1) {
            printf("Failed to read from the serial port: \n%s\n", strerror(errno));
            return 1;
        }

        // Detect a newline
        if (c == '\n' || c == '\r') {
            if (buf_idx > 0) {
                buf[buf_idx] = 0;
				url2[buf_idx]=0;
                buf_idx = 0;

                /* buf now contains a complete line of text */
                printf("Received: %s\n", buf);
				char * url1[150];
				//url1={"https://data.sparkfun.com/input/dZqnXrRJZOT5Oq8yjoy5?private_key=eEVnrkG1EMu8NDmxVrx8&" 0}; 
			//	strcat(url1, "https://data.sparkfun.com/input/dZqnXrRJZOT5Oq8yjoy5?private_key=eEVnrkG1EMu8NDmxVrx8&");

				//strcat(url1, url2);
				printf("url:%s%s\n", url1, url2);
				
				 // curl = curl_easy_init();
					//if(curl) {
					//	curl_easy_setopt(curl, CURLOPT_URL,&^%$%^& );
					//	/* example.com is redirected, so we tell libcurl to follow redirection */ 
					//	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
					//	/* Perform the request, res will get the return code */ 
					//	res = curl_easy_perform(curl);
					//	/* Check for errors */ 
					//	if(res != CURLE_OK)
					//	  fprintf(stderr, "curl_easy_perform() failed: %s\n",
					//			  curl_easy_strerror(res));
 
					//	/* always cleanup */ 
					//	curl_easy_cleanup(curl);
					//  }
					//  return 0;


            }
        } else if (buf_idx < BUF_SIZE-1) { // -1 to allow room for the NULL
            // Store the result
            buf[buf_idx++] = c;
			url2[buf_idx]=c;
        }
    }
}

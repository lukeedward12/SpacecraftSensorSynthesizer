#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>

// TODO: REMOVE
#include "iostream"
#include <string.h>

namespace networking {

/**
 * @brief
 *
 *
 * @tparam port
 */
template <uint16_t port> class client {
      public:
	/**
	 * @brief Setup client Socket
	 *
	 */
	void setup() {
		printf("\n Setting up client socket!\n");
		address.sin_family = AF_INET;
		address.sin_port = htons(port);
		int status = 0;

		if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			printf("\n Socket creation error \n");
			return;
		}

		// Convert IPv4 and IPv6 addresses from text to binary
		// form
		if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <=
		    0) {
			printf(
			    "\nInvalid address/ Address not supported \n");
			return;
		}
	}

	/**
	 * @brief Try to connect to to a server socket. Try for 10 times
	 * over 10 seconds before erroring out.
	 *
	 */
	void connect_to_server() {
		printf("\n Attempting to connect to Server Socket...\n");
		int status = 0;
		status = connect(client_fd, (struct sockaddr *)&address,
				 sizeof(address));
		if (status < 0) {
			printf("\nConnection Failed \n");
			return;
		}
		printf("\n Finished waiting for a server...!\n");
	}

	/**
	 * @brief Read data from socket.
	 *
	 */
	void read_data() {
		char buffer[300] = {0};
		read(client_fd, buffer, 300);
		printf("Message received from client: %s\n", buffer);
	}

	/**
	 * @brief Write data to the socket
	 *
	 */
	void write_data() {
		const char *hello = "Hello from client";
		send(client_fd, hello, strlen(hello), 0);
		printf("Hello message sent\n");
	}

      protected:
      private:
	int client_fd = 0;
	struct sockaddr_in address {};
};

} // namespace networking
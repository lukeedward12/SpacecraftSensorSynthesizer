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
template <uint16_t port> class server {
      public:
	server() {}

	/**
	 * @brief Setup Server Socket
	 *
	 */
	void setup() {
		printf("\n Setting up server socket!\n");
		char buffer[1024] = {0};
		char *hello = "Hello from server";

		// Creating socket file descriptor
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			perror("socket failed");
			exit(EXIT_FAILURE);
		}

		// Forcefully attaching socket to the port 8080
		if (setsockopt(server_fd, SOL_SOCKET,
			       SO_REUSEADDR | SO_REUSEPORT, &opt,
			       sizeof(opt))) {
			perror("setsockopt");
			exit(EXIT_FAILURE);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(port);

		// Forcefully attaching socket to the port 8080
		if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address)) < 0) {
			perror("bind failed");
			exit(EXIT_FAILURE);
		}
		if (listen(server_fd, 3) < 0) {
			perror("listen");
			exit(EXIT_FAILURE);
		}

		if (listen(server_fd, 3) < 0) {
			perror("listen");
			exit(EXIT_FAILURE);
		}

		printf("\n Server Socket Setup!\n");
	}

	/**
	 * @brief Wait for a client to connect to socket. Try for 10 times
	 * over 10 seconds before erroring out.
	 *
	 */
	void wait_for_client() {
		printf("\n Waiting for a client connection...!\n");
		new_socket = accept(server_fd, (struct sockaddr *)&address,
				    (socklen_t *)&addrlen);

		for (uint8_t i = 0; i < 10; i++) {
			// if ((new_socket = accept(
			//	 server_fd, (struct sockaddr *)&address,
			//	 (socklen_t *)&addrlen)) < 0) {
			//
			//	// printf("\nConnection Unsuccessful with "
			//	//        "Client! Sleeping for 1 second
			//	//        and " "trying " "again \n");
			//	//
			//	// std::this_thread::sleep_for(
			//	//    std::chrono::seconds(1));
			//} else {
			//	// printf("\nConnection Successful with "
			//	//        "Client! \n");
			//	break;
			//}
		}
		printf("\n Finished waiting for a client...!\n");
		return;
	}

	/**
	 * @brief Read data from socket.
	 *
	 */
	void read_data() {
		// char buffer[300] = {0};
		// read(sock, buffer, 300);
		// printf("Message received from server: %s\n", buffer);
	}

	/**
	 * @brief Write data to the socket
	 *
	 */
	void write_data() {
		// const char *hello = "Hello from client";
		// send(sock, hello, strlen(hello), 0);
		// printf("Hello message sent\n");
	}

      protected:
      private:
	int server_fd = 0;
	int new_socket = 0;
	int valread = 0;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	int opt = 1;
};

} // namespace networking
#include "networking.hh"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>
#include <vector>

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
	return_codes setup() {
		printf("\n Setting up client socket!\n");
		address.sin_family = AF_INET;
		address.sin_port = htons(port);
		int status = 0;

		if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
			printf("\n Socket creation error \n");
			return return_codes::FAILURE;
		}

		// Convert IPv4 and IPv6 addresses from text to binary
		// form
		if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <=
		    0) {
			printf(
			    "\nInvalid address/ Address not supported \n");
			return return_codes::FAILURE;
		}

		return return_codes::SUCCESS;
	}

	/**
	 * @brief Try to connect to to a server socket. Try for 10 times
	 * over 10 seconds before erroring out.
	 *
	 */
	return_codes connect_to_server() {
		printf("\n Attempting to connect to Server Socket...\n");
		int status = 0;
		status = connect(client_fd, (struct sockaddr *)&address,
				 sizeof(address));
		if (status < 0) {
			printf("\nConnection Failed \n");
			return return_codes::FAILURE;
		}
		printf("\n Finished waiting for a server...!\n");
		return return_codes::SUCCESS;
	}

	/**
	 * @brief Read data from socket.
	 *
	 */
	return_codes read_data(const std::vector<uint8_t> &data) {

		return return_codes::SUCCESS;
	}

	/**
	 * @brief Write data to the socket
	 *
	 */
	return_codes write_data(const std::vector<uint8_t> &data) {
		printf("\n Sending data to the server...!\n");

		ssize_t bytesSent =
		    send(client_fd, data.data(), data.size(), 0);

		printf("\n Sent %i bytes to the server...!\n", bytesSent);
		return return_codes::SUCCESS;
	}

      protected:
      private:
	int client_fd = 0;
	struct sockaddr_in address {};
};

} // namespace networking
#ifndef SOCKET_HH
#define SOCKET_HH

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <vector>

// TODO: REMOVE
#include "iostream"
#include <string.h>

namespace networking {

class network_socket {

      public:
	network_socket() {}

	/**
	 * @brief Write data to the socket
	 *
	 */
	return_codes write_data(const std::vector<uint8_t> &data) {
		printf("\n Sending data to the server...!\n");

		ssize_t bytesSent =
		    send(connected_socket, data.data(), data.size(), 0);

		printf("\n Sent %i bytes to the server...!\n", bytesSent);
		return return_codes::SUCCESS;
	}

	/**
	 * @brief Read data from socket.
	 *
	 */
	std::vector<uint8_t> read_data() {
		size_t dataSize = 1024;
		uint8_t read_buffer[dataSize] = {};
		ssize_t bytesRead =
		    recv(connected_socket, read_buffer, dataSize, 0);

		// Read the socket but be verbose if we error out
		if (bytesRead == -1) {
			std::cerr << "Error reading from socket: "
				  << strerror(errno) << std::endl;
		}

		std::vector<uint8_t> return_vector(
		    read_buffer, read_buffer + bytesRead);

		printf("\n Read %i bytes from the client...!\n",
		       bytesRead);

		return return_vector;
	}

      protected:
	int pending_socket = 0;
	int connected_socket = 0;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	int opt = 1;

      private:
};

} // namespace networking

#endif
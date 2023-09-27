#ifndef SERVER_HH
#define SERVER_HH

#include "networking.hh"
#include "socket.hh"

namespace networking {

/**
 * @brief TCP Server Class
 *
 *
 * @tparam port
 */
template <uint16_t port> class server : public network_socket {
      public:
	server() {}

	/**
	 * @brief Setup Server Socket
	 *
	 */
	return_codes setup() {
		printf("\n Setting up server socket!\n");

		// Creating socket file descriptor
		if ((pending_socket = socket(AF_INET, SOCK_STREAM, 0)) <
		    0) {
			perror("socket failed");
			exit(EXIT_FAILURE);
			return return_codes::FAILURE;
		}

		// Forcefully attaching socket to the port 8080
		if (setsockopt(pending_socket, SOL_SOCKET,
			       SO_REUSEADDR | SO_REUSEPORT, &opt,
			       sizeof(opt))) {
			perror("setsockopt");
			exit(EXIT_FAILURE);
			return return_codes::FAILURE;
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(port);

		// Forcefully attaching socket to the port 8080
		if (bind(pending_socket, (struct sockaddr *)&address,
			 sizeof(address)) < 0) {
			perror("bind failed");
			exit(EXIT_FAILURE);
			return return_codes::FAILURE;
		}
		if (listen(pending_socket, 3) < 0) {
			perror("listen");
			exit(EXIT_FAILURE);
			return return_codes::FAILURE;
		}

		printf("\n Server Socket Setup!\n");
		return return_codes::SUCCESS;
	}

	/**
	 * @brief Wait for a client to connect to socket.
	 *
	 */
	return_codes wait_for_client() {
		printf("\n Waiting for a client connection...!\n");

		// TODO: Timeout and report an error
		connected_socket =
		    accept(pending_socket, (struct sockaddr *)&address,
			   (socklen_t *)&addrlen);

		if (connected_socket < 0) {
			printf("\nConnection Failed \n");
			return return_codes::FAILURE;
		}

		printf("\n Finished waiting for a client...!\n");
		return return_codes::SUCCESS;
	}

      protected:
      private:
};

} // namespace networking

#endif
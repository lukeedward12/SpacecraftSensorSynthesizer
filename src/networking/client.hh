#ifndef CLIENT_HH
#define CLIENT_HH

#include "networking.hh"
#include "socket.hh"

namespace networking {

/**
 * @brief
 *
 *
 * @tparam port
 */
template <uint16_t port> class client : public network_socket {
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

		if ((pending_socket = socket(AF_INET, SOCK_STREAM, 0)) <
		    0) {
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
		status =
		    connect(pending_socket, (struct sockaddr *)&address,
			    sizeof(address));
		if (status < 0) {
			printf("\nConnection Failed \n");
			return return_codes::FAILURE;
		}
		printf("\n Finished waiting for a server...!\n");

		connected_socket = pending_socket;
		return return_codes::SUCCESS;
	}

      protected:
      private:
};

} // namespace networking

#endif
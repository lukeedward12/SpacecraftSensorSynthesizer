#include "logger.hh"
#include "server.hh"
#include <chrono>
#include <thread>

namespace logger {
return_code
init(networking::server<networking::logger_server_port> &logger_server);
return_code core_loop(
    networking::server<networking::logger_server_port> &logger_server);
} // namespace logger

/**
 * @brief
 *
 *
 * @param logger_server
 * @return
 */
logger::return_code logger::init(
    networking::server<networking::logger_server_port> &logger_server) {
	// Init TCP server for receiving sensor measurements
	networking::return_codes status;

	status = logger_server.setup();
	if (status != networking::return_codes::SUCCESS) {
		return return_code::FAILURE;
	}

	status = logger_server.wait_for_client();
	if (status != networking::return_codes::SUCCESS) {
		return return_code::FAILURE;
	}

	return return_code::SUCCESS;
}

logger::return_code logger::core_loop(
    networking::server<networking::logger_server_port> &logger_server) {
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::vector<uint8_t> read_data = logger_server.read_data();
	}
	return return_code::SUCCESS;
}

void logger::logger_thread() {
	// Create TCP server for receiving sensor measurements
	networking::server<networking::logger_server_port> logger_server;

	while (init(logger_server) != return_code::SUCCESS) {
		printf("\n Logger Init Failed - Trying again \n");
	}

	printf("\n Logger starting core loop \n");
	core_loop(logger_server);

	return;
}
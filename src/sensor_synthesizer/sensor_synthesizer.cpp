#include "sensor_synthesizer.hh"
#include "client.hh"
#include "comm_types.hh"
#include "server.hh"
#include <chrono>
#include <thread>

namespace sensor_synthesizer {
return_code
init(networking::server<networking::S3_server_port> &sensor_syn_server,
     networking::client<networking::logger_server_port> &logger_client);
return_code core_loop(
    networking::server<networking::S3_server_port> &sensor_syn_server);
} // namespace sensor_synthesizer

/**
 * @brief Initializes the Sensor Synthesizer Thread:
 * - Measurement Server Socket
 * - Logger Client Socket
 *
 *
 * @return Status Return Code
 */
sensor_synthesizer::return_code sensor_synthesizer::init(
    networking::server<networking::S3_server_port> &sensor_syn_server,
    networking::client<networking::logger_server_port> &logger_client) {
	// Init TCP server for receiving sensor measurements
	networking::return_codes status =
	    networking::return_codes::FAILURE;

	while (status != networking::return_codes::SUCCESS) {
		status = sensor_syn_server.setup();
		status = sensor_syn_server.wait_for_client();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	while (status != networking::return_codes::SUCCESS) {
		status = logger_client.setup();
		status = logger_client.connect_to_server();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return return_code::SUCCESS;
}

sensor_synthesizer::return_code sensor_synthesizer::core_loop(
    networking::server<8080> &sensor_syn_server) {
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::vector<uint8_t> read_data =
		    sensor_syn_server.read_data();
	}
	return return_code::SUCCESS;
}

void sensor_synthesizer::sensor_synthesizer_thread() {

	// Create TCP server for receiving sensor measurements
	networking::server<networking::S3_server_port> sensor_syn_server;
	networking::client<networking::logger_server_port> logger_client;

	while (init(sensor_syn_server, logger_client) !=
	       return_code::SUCCESS) {
		printf("\n Sensor Synthesizer Failed - Trying again \n");
	}

	core_loop(sensor_syn_server);
	return;
}
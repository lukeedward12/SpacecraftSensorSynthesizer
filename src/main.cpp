#include "client.hh"
#include "comm_types.hh"
#include "logger.hh"
#include "sensor_synthesizer.hh"
#include "server.hh"
#include <chrono>
#include <thread>
#include <vector>

constexpr uint8_t core_sleep_time = 1;

int main() {
	printf("\n SIM: FSW Task Manager has started! \n");

	// Create S3 Thread
	printf("\n SIM: Starting S3 Thread \n");
	std::thread s3_thread(
	    sensor_synthesizer::sensor_synthesizer_thread);

	// Create Logger Thread
	printf("\n SIM: Starting Logging Thread \n");
	std::thread logger_thread(logger::logger_thread);

	// Create client socket to populate S3 with Data
	networking::client<8080> main_client;
	networking::return_codes status;
	status = main_client.setup();
	status = main_client.connect_to_server();

	comm_types::mag_measurement mag_measurement;
	std::vector<uint8_t> mag_measurement_serialized(
	    sizeof(mag_measurement));

	// Serialize the data
	std::copy(reinterpret_cast<const uint8_t *>(&mag_measurement),
		  reinterpret_cast<const uint8_t *>(&mag_measurement) +
		      sizeof(mag_measurement),
		  mag_measurement_serialized.begin());

	// At X Hz, send data to the Sensor Synthesizer
	while (true) {
		std::this_thread::sleep_for(
		    std::chrono::seconds(core_sleep_time));
		status =
		    main_client.write_data(mag_measurement_serialized);
	}

	s3_thread.join();
	logger_thread.join();
	return 0;
}
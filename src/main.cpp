#include "client.hh"
#include "logger.hh"
#include "sensor_synthesizer.hh"
#include "server.hh"
#include <thread>

int main() {
	printf("\n SIM: FSW Task Manager has started! \n");

	networking::client<8080> main_client;

	printf("\n SIM: Starting S3 Thread \n");
	std::thread s3_thread(
	    sensor_synthesizer::sensor_synthesizer_thread);

	printf("\n SIM: Starting Logging Thread \n");
	std::thread logger_thread(logger::logger_thread);

	s3_thread.join();
	logger_thread.join();
	return 0;
}
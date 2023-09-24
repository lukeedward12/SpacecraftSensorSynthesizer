#include "client.hh"
#include "logger.hh"
#include "sensor_synthesizer.hh"
#include "server.hh"
#include <thread>

int main() {

	networking::server<8080> main_server;
	networking::client<8080> main_client;

	std::thread s3_thread(
	    sensor_synthesizer::sensor_synthesizer_thread);

	std::thread logger_thread(logger::logger_thread);

	s3_thread.join();
	logger_thread.join();
	return 0;
}
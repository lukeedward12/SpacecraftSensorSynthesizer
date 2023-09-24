#include "logger.hh"
#include "sensor_synthesizer.hh"
#include <thread>

int main() {
	std::thread s3_thread(
	    sensor_synthesizer::sensor_synthesizer_thread);

	std::thread logger_thread(logger::logger_thread);

	s3_thread.join();
	logger_thread.join();
	return 0;
}
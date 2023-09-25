#include "sensor_synthesizer.hh"
#include "server.hh"

namespace sensor_synthesizer {
void init();
}

void sensor_synthesizer::init() {
	networking::server<8080> sensor_syn_server;
	sensor_syn_server.setup();
	sensor_syn_server.wait_for_client();
	return;
}

void sensor_synthesizer::sensor_synthesizer_thread() {

	init();
	while (true) {
	}
	return;
}
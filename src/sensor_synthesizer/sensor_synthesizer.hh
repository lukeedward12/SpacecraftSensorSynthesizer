#ifndef SENSOR_SYNTHESIZER_HH
#define SENSOR_SYNTHESIZER_HH

namespace sensor_synthesizer {

/**
 * @brief THREAD: Sensor Synthesizer Thread - controls the reception of
 * sensor data from a socket, performs runtime analysis on sensor data at 1
 * Hz, and reports runtime analysis to a logger thread over a socket
 *
 */
void sensor_synthesizer_thread();

} // namespace sensor_synthesizer

#endif
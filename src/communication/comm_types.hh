#ifndef COMM_TYPES_HH
#define COMM_TYPES_HH

#include <stdint.h>

namespace comm_types {

enum measurement_id { MAG, PCSS, STAR_TRACKER, IMU, THERMISTOR, CURRENT };

/**
 * @brief Generic Measurement Entry Structure
 *
 */
template <typename measurement_type, measurement_id input_id>
struct sensor_reading {
	const measurement_id id = input_id;
	measurement_type measurement;
};

/**
 * @brief Magnetometer Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::MAG> mag_measurement;

/**
 * @brief PCSS Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::PCSS> pcss_measurement;

/**
 * @brief Star Tracker Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::STAR_TRACKER>
    star_tracker_measurement;

/**
 * @brief IMU Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::IMU> imu_measurement;

/**
 * @brief Thermistor Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::THERMISTOR>
    thermistor_measurement;

/**
 * @brief Current Measurement Entry Structure
 *
 */
typedef sensor_reading<uint8_t, measurement_id::CURRENT>
    current_measurement;

} // namespace comm_types

#endif
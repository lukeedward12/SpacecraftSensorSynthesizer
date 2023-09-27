#ifndef NETWORKING_HH
#define NETWORKING_HH

#include <stdint.h>

namespace networking {
/**
 * @brief Networking Return Codes
 */
enum return_codes { SUCCESS, FAILURE, TIMEOUT };

constexpr uint32_t S3_server_port = 8080;
constexpr uint32_t logger_server_port = 8888;

} // namespace networking

#endif
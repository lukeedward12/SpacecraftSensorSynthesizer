#ifndef LOGGER
#define LOGGER

namespace logger {

enum return_code { SUCCESS, FAILURE, TIMEOUT };

/**
 * @brief THREAD: Logger Thread - receives sensor data over a socket and
 * outputs data through a debut output (stdout, peripheral, log file, etc)
 */
void logger_thread();
} // namespace logger

#endif // LOGGER
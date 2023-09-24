#ifndef LOGGER
#define LOGGER

namespace logger {
/**
 * @brief THREAD: Logger Thread - receives sensor data over a socket and
 * outputs data through a debut output (stdout, peripheral, log file, etc)
 */
void logger_thread();
} // namespace logger

#endif // LOGGER
#include <netinet/in.h>
#include <sys/socket.h>

namespace networking {

/**
 * @brief
 *
 *
 * @tparam port
 */
template <uint16_t port> class client {
      public:
	client() {}
	void setup();
	void read();
	void write();

      protected:
      private:
};

} // namespace networking
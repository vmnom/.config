#include <rwx.h>

extern "C" void service (controller* ctrl) {

	auto index = [] () {
		std::cout << "hello world";
	};
}

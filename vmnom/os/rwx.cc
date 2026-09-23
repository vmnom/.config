#include <rwx.h>

std::string homePath;

int main() {

	dlerror();

	const char *home = std::getenv("HOME");

	if (home) {

		homePath = std::string(home) + "/.config/vmnom/public";

	}

	else

		return EXIT_FAILURE;

	std::string vendor = std::string(homePath) + "/vendor";

	/*
	 * Global static controller instance.
	 * Created once and shared throughout the program.
	 */

	static controller base{};

	for (const auto& entry : fs::directory_iterator(vendor)) {

		if (!entry.is_regular_file())

			continue;

		void* file = dlopen(entry.path().c_str(), RTLD_NOW);

		if (!file) {

			std::cerr << "dlopen: " << dlerror() << '\n';

			continue;
		}

		service map = reinterpret_cast<service>(dlsym(file, "map"));

		map(&base);
	}


	return 0;
};



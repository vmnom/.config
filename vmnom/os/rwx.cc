#include <rwx.h>

void _start(service ctrl) {
	std::cout << "_start";
}

int main() {

	config_dir /= ".config/vmnom/public/vendor";

	using nmap = void (*) (service*);

	service ctrl;

	for (const auto& entry : filesystem::directory_iterator(config_dir)) {

		if (!entry.is_regular_file())
			continue;

		void* file = dlopen(entry.path().c_str(), RTLD_NOW);

		if (!file) {
			std::cerr << "dlopen: " << dlerror() << '\n';
			continue;
		}

		nmap srv = reinterpret_cast<nmap>(dlsym(file, "nmap"));

		if (!srv) {
			std::cerr << "Failed to find 'service' symbol: " << dlerror() << "\n";
			return EXIT_FAILURE;
		}

		srv(&ctrl);
	};

	_start(ctrl);

	return EXIT_SUCCESS;
};

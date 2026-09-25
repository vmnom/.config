#include <rwx.h>

int main() {

	kernel ctrl {
	};

	filesystem::path config_dir(getenv("HOME"));

	config_dir /= ".config/vmnom/public/vendor";

	for (const auto& entry : filesystem::directory_iterator(config_dir)) {

		if (!entry.is_regular_file())

			continue;

		void* file = dlopen(entry.path().c_str(), RTLD_NOW);

		if (!file) {

			std::cerr << "dlopen: " << dlerror() << '\n';

			continue;
		}

		using servive = void (*) (kernel*);

		service srv = reinterpret_cast<service>(dlsym(file, "service"));

		if (!srv) {

			std::cerr << "Failed to find 'service' symbol: " << dlerror() << "\n";

			return EXIT_FAILURE;
		}

		srv(&ctrl);

	};

	return EXIT_SUCCESS;
};

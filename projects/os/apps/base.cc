#include <dlfcn.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {

	dlerror();

	const std::string folder = "public/vendor";

	for (const auto& entry : fs::directory_iterator(folder)) {

		if (!entry.is_regular_file())

			continue;

		const auto& path = entry.path();

		void* _sitemap = dlopen(path.c_str(), RTLD_NOW);

		if (!_sitemap) {

			std::cerr << "dlopen: " << dlerror() << '\n';

			continue;
		}

		// using map = void (*)();
		//
		// map controller = reinterpret_cast<map>(dlsym(_sitemap, "map"));
		//
		// controller();
	}

	return 0;
}

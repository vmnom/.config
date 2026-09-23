#ifndef BASE_H
#define BASE_H

struct controller {
	int value;
};

using service = void (*)(controller*);


#include <dlfcn.h>
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <iostream>

namespace fs = std::filesystem;

#endif

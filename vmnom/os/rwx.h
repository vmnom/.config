#ifndef BASE_H
#define BASE_H

#include <vector>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>

using namespace std;

typedef struct router router;

struct router {
	string unique;
};

typedef struct service service;

struct service {
	vector<router> routes;
};

#endif

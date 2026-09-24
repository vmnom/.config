#ifndef BASE_H
#define BASE_H

#include <vector>
#include <dlfcn.h>
#include <iostream>
#include <filesystem>

using namespace std;

typedef struct router router;

typedef struct controller controller;

struct controller {
	vector<router> routes;
};

struct router {
	string unique;
	controller method;
};

#endif

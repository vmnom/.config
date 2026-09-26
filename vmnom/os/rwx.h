#ifndef BASE_H
#define BASE_H

#include <vector>
#include <dlfcn.h>
#include <iostream>
#include <sqlite3.h>
#include <filesystem>

using namespace std;

typedef struct service service;

typedef struct router router;

struct router {
	string unique;
};

struct service {

	vector<router>* resolve(string name) {

		return &routes;
	}

	vector<router> routes;

	sqlite3* db;
};

inline filesystem::path config_dir(getenv("HOME"));

#endif

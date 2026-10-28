#ifndef RWX_H
#define RWX_H

#include <index.h>

struct request {

	int id;

	string raw;

};

struct playground : nosql {

	unordered_map<string, function<void(nosql*)>> prototype;

	void verify() {}

};

#endif

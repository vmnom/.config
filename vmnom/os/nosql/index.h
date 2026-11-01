#ifndef NOSQL_H
#define NOSQL_H

struct Any;
struct nosql;

#include <map>
#include <string>
#include <iostream>

using namespace std;

struct Nosql {
	nosql* value;
};

struct Double {
	int value;
};

struct String {
	string value;
};

#endif

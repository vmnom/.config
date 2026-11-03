#ifndef NOSQL_H
#define NOSQL_H

#include <map>
#include <string>
#include <iostream>

struct object;
struct Nosql;

using namespace std;

/*
 * Nosql prototype
 */

class Nosql : map<string, Nosql*> {

	public:
		Nosql(string text) {};
};

class object : public Nosql {

	public:

		void option(string key, Nosql value) {
		}

};

#endif

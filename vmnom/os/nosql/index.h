#ifndef NOSQL_H
#define NOSQL_H

struct nosql;
struct window;

#include <map>
#include <string>
#include <stdio.h>
#include <variant>

using namespace std;

struct prototype : map<string, string> {

	nosql* console;

	void join(nosql* value) {
		console = value;
	}

	void assign (string, string);
	void valueOf (void);

};

struct window : prototype {

	void log(prototype* ptr) {

		iterator it;

		for (it = (*ptr).begin(); it != (*ptr).end(); ++it) {

			printf("%s = %d\n",

					it->first.c_str(),

					it->second

			      );

		}

	}

};

struct nosql : window {
	void init() {
		join(this);
	}
};

inline void prototype::assign(string key, string value) {
	(*this)[key] = value;
}

inline void prototype::valueOf() {
	(*console).log(this);
}

#endif

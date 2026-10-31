#ifndef NOSQL_H
#define NOSQL_H

struct nosql;
struct prototype;

#include <map>
#include <string>
#include <variant>
#include <iostream>

using namespace std;

struct prototype : map<string, nosql*> {

	nosql* console;

	void join(nosql* value) {

		console = value;

	}

	void assign (string, nosql*);

	void valueOf (void);

	string first() {
		return this->begin()->first;
	}

};

struct window : prototype {

	void log(prototype* ptr) {

		iterator it;

		cout << first() << endl;

	}

};

struct nosql : window {

	void init(prototype* parent) {

		parent->join(this);

	}

	string toString() {
		return "hi";
	}

};

inline void prototype::assign(string key, nosql* value) {

	(*this)[key] = value;

}

inline void prototype::valueOf() {

	(*console).log(this);

}

#endif

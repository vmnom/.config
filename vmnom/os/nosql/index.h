#ifndef NOSQL_H
#define NOSQL_H

struct nosql;

#include <map>
#include <string>
#include <variant>
#include <iostream>

using namespace std;

using Template = variant<string, int, nosql*>;

struct console {

	void log(map<string, Template>* options) {

		for (const auto& [key, value] : *options) {

			cout << key << endl;

		}

	}

};

struct prototype : map<string, Template>, console {

	string selected;

	prototype* select(string key) {

		selected = key;

		return this;

	}

	prototype* assign(string key, Template value) {

		(*this)[key] = value;

		return this;

	}

	void valueOf() {

		log(this);

	}

};

struct nosql : prototype {};

#endif

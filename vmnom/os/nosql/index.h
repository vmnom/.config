#ifndef NOSQL_H
#define NOSQL_H

struct Any;

struct nosql;

#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct String {

	string value;

};

struct Int {

	int value;

};

struct Nosql {

	nosql* value;

};

struct protocol : map<string, Any*> {

	void add (string key, Any* value) {

		(*this)[key] = value;

	}

	bool load (string key, Any* target) {

		target = (*this)[key];

		return target;
	}

};

struct Any {

	public:

		String text;

		Any(string value) {

			text = {value};

		}

		Int number;

		Any(int value) {

			number = {value};

		}

		Nosql node;

		Any(nosql* value) {

			node = {value};

		}

	public:

		Any* parent;

		protocol prototype;

		void option (string key, Any value) {

			parent = this;

			prototype.add(key, this);
			
			depth = parent->depth + 1;

		}


	public:

		string value(string key) {

			return text.value;

		};

		string serial(string key) {

			Any* target;

			if(!prototype.load("email", target)) {

				return "{}";

			}

			return "{\r\n" + string(depth, '\t') + key + ":" + target->value(key) + "\r\n}";

		}

	protected:

		int depth = 0;

		void typing(string&buffer, string key, string node) {

			buffer += "\r\n" + string(depth,'\t') + key + ":" + node;

		}
};

#endif

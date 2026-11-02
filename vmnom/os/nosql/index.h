#ifndef NOSQL_H
#define NOSQL_H

struct Any;

struct nosql;

#include <map>
#include <string>
#include <iostream>

using namespace std;

struct History : map<string, Any*> {};

struct Any : History {

	protected:

		Any* prototype;

	public:

		string text;

		Any(string value) {

			text = value;

		}

		int number;

		Any(int value) {

			number = value;

		}

		string value() {

			if(!text.empty())

				return text;

			return "undefined";

		};

	public:

		void option (string key, Any value) {

			(*this)[key] = {&value};

		}

		string valueOf () {

			string object;

			map<string, Any*>::iterator it = begin();

			for(const auto& item : *this) {
				object += item.first;
				object += ":";
				object += item.second->value() + "\r\n";
			}

			return object;

		}

};

#endif

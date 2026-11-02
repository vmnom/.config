#ifndef NOSQL_H
#define NOSQL_H

struct Any;

struct nosql;

#include <map>
#include <string>
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

};

struct Any {

	protected:

		int depth = 0;

	public:

		string valueOf() {

			if(!text.value.empty())

				return text.value;

			return "undefined";

		};

		String text;

		Any(const string value) {

			text = {value};

		}

		Int number;

		Any(int value) {

			number = {value};

		}

		Nosql ppt;

		Any(nosql* value) {

			ppt = {value};

		}

	public:

		protocol prototype;

		void option (string key, Any value) {

			prototype.add(key, this);

		}

		string jsonKeyword(string key) {

			return key;

		};

		string serial() {

			string results = "{}";

			if(!prototype.empty()) {

				results = "{";

				int t = 1;

				for (const auto& option : prototype) {

					results += "\n" + string(depth + t, '\t') + option.first + ": " + option.second->valueOf();

				}

				results += "\n" + string(depth, '\t') + "}";

			}

			return results;

		}

};

#endif

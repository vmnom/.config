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

	Any* load (string key) {

		return (*this)[key];

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

		string value() {

			if(!text.value.empty())

				return text.value;

			if(number.value) {

				char str[32];

				sprintf(str, "%d", number.value);

				return str;
			}


			return "undefined";

		};

		string serial(string key) {

			Any* target = prototype.load("email");

			if(!target) {

				return "{}";

			}

			return target->value();

			string buffer = "{";

			typing(

					buffer, 
					key,
					"vv"
						);

			/* 				int t = 1; */

			/* 				for (const auto& option : prototype) { */

			/* 					results += "\n" + string(depth + t, '\t') + option.first + ": " + option.second->valueOf(); */

			/* 				} */

			/* 				results += "\n" + string(depth, '\t') + "}"; */

			/* 			} */


			return buffer;

		}

	protected:

		int depth = 0;

		void typing(string&buffer, string key, string node) {

			buffer += "\r\n" + string(depth,'\t') + key + ":" + node;

		}
};

#endif

#ifndef NOSQL_H
#define NOSQL_H

#include <index.h>

/*
 * Nosql vb
 */

class Nosql : public map<string, Nosql*> {

	string recieve;

	public:

		int indent = 1;

		Nosql* prototype;

		Nosql(clock_t value) {

			recieve = to_string(value);

		}

		Nosql(int dep) {

			stringstream str;

			str << dep;

			recieve = str.str();

		}

		Nosql(string value) {

			recieve = value;

		}

		string value() {

			string v = recieve;

			return v;

		}

	public:

		void option(string key, Nosql* item) {

			(*this)[key] = item;

		}

		string valueOf() {

			if(size()) {

				return "x\t ::(" + size() + 0;

			}

			if(!prototype)

				return value();


			return "undefined";

		}

	public:

		string mail() {

			prototype = this;

			option("Return-Type", 0);

			return  valueOf();

		}

};

#endif

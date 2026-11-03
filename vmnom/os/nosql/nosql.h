#ifndef NOSQL_H
#define NOSQL_H

#include <map>
#include <string>
#include <iostream>

struct Nosql;

struct object;

using namespace std;

/*
 * Nosql prototype
 */

class Nosql : public map<string, Nosql*> {

	protected:

		Nosql* prototype;

	public:

		string recieve;

		Nosql(int deprecated) {

			recieve = to_string(deprecated);

		}

		Nosql(string value) {

			recieve = value;

		}

		string value() {

			return recieve;

		}

	public:

		int depth = 1;

		void option(string key, Nosql prototype) {

			(*this)[key] = &prototype;

		}

		Nosql* select(string key) {

			return (*this)[key];

		}

		string valueOf() {

			string ss = "{";

			for(const auto& item : *this) {

				ss += '\n';

				ss += string(depth, '\t');

				ss += item.first;

				ss += " : ";

				ss += item.second->value();

			}

			return ss + "\n" + string(depth -1 , '\t') + "}";

		}

	public:

		void test() {

			cout << endl << "vmnom/nosql, tests" << endl;

			prototype = this;

			prototype->option("inbox", {0});

			cout << prototype->valueOf();

		}

};

#endif

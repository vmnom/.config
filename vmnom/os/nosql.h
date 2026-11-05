#ifndef NOSQL_H
#define NOSQL_H

#include <index.h>

struct Nosql;

using namespace std;

/*
 * Nosql prototype
 */

class Nosql : public map<string, Nosql*> {

	private:

		int indent = 1;

		string recieve;

		Nosql* prototype;

	public:

		Nosql(int dep) {

			stringstream str;

			str << dep;

			recieve = str.str();

		}

		Nosql(string value) {

			recieve = value;

		}

		string value() {

			return recieve;

		}

	public:

		void option(string key, Nosql* prototype) {

			(*this)[key] = prototype;

		}

		string valueOf(int indent = 0) {

			if(size()) {

				iterator n;

				string args;

				for(n = begin(); n != end(); ++n) {

					args += "\n";

					args += string(indent, '\t');

					args += n->first;

					if(n->second)

					args += ":" + n->second->valueOf(indent + 1);

					else

						args += ": undefined";

				}

				return args;

			}

			if(prototype)

				return prototype->valueOf(zdepth);

			return value();

		}

	public:

		string mail() {

			Nosql inbox(0);

			inbox.option("log", 0);

			inbox.option("log2", 0);

			option("inbox", &inbox);

			Nosql cv(0);

			cv.option("key", 0);

			inbox.option("log3", &cv);

			option("mail", &inbox);

			prototype = this;

			return valueOf();

		}
};

#endif

#ifndef NOSQL_H
#define NOSQL_H

#include <index.h>

/*
 * Nosql vb
 */

class Nosql : public map<string, Nosql*> {

	protected:

		string value() {

			return recieve;

		}

		string recieve;

	public:

		Nosql* prototype;

		Nosql(int dep) {

			stringstream str;

			str << dep;

			recieve = str.str();

		}

		Nosql(string value) {

			recieve = value;

		}

	public:

		void option(string key, Nosql s) {

			(*this)[key] = &s;

		}

		void assign(string key, Nosql s) {

			option(key, s);

		}


		string valueOf() {

			string args;


			if(size()) {

				args += toString();

			}

			if(prototype != nullptr) {

				args += toString();

			}

			return args;
		}

		string toString() {

			return ":";

			string buffer = "{";

			map<string, Nosql*>::iterator restore = prototype->begin();

			for (restore; restore != prototype->end(); ++restore)
			{

				buffer += "\n";
				buffer += string(1, '\t');
				buffer += restore->first + ": ";

				if(restore->second) {
				
					buffer += restore->second->valueOf();

					cout << buffer;

					return ":";

				}

				buffer += "undefined";

			}

			buffer += "\n";

			buffer += "}";

			return buffer;

		}

	public:

		string inbox() {

			Nosql console(0);

			prototype = this;

			console.option("log", Nosql("desription"));

			console.option("Subject", Nosql("desription"));

			prototype->option("console", console);

			int i = 0;

			for (i; i < 1; ++i) {

				option("To", Nosql(i));

			}

			return  (*this).valueOf();

		}

};

void incoming(Nosql* eml ) {

	cout << endl;

	cout << eml->inbox();

	cout << endl;

}

#endif

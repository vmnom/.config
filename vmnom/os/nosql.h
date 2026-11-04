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

		void option(string key, Nosql* item) {

			(*this)[key] = item;

			(*this)[key]->indent = indent + 1;

		}

		string valueOf() {

/* 			if(size()) { */

/* 				string ss = "{"; */

/* 				iterator vertical; */

/* 				/1* for(vertical = begin(); vertical != end(); ++vertical) { *1/ */

/* 					/1* ss += '\n'; *1/ */
/* 					/1* ss += string(indent, '\t'); *1/ */

/* 				/1* } *1/ */

/* 				return ss + "\n" + string(indent -1 , '\t') + "}"; */

/* 			} */

/* 			if(!prototype) */

/* 				return value(); */


			return "undefined";

		}

	public:

		string mail() {

			/* prototype = this; */

			option("inbox", 0);

			return valueOf();

		}
};

#endif

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

struct Compiler {

	protocol prototype;

};

struct Any : Compiler {

	protected:

		int counter = 0;

	public:

		Int number;

		Any(int value) {
			number = {value};
		}

		Nosql ppt;

		Any(nosql* value) {
			ppt = {value};
		}

		String text;

		Any(const string value) {
			text = {value};
		}

		string toString() {

			return "value";

		}

	public:

		int n = 1;

		void option (string key, Any value) {

			prototype.add(key, this);

		}

		void log(int level = 0) {

			const string BRAKETOPEN = "{\r\n\t";
			const string BRAKETCLOSE = "}";


			cout << BRAKETOPEN << endl;

			for (const auto& option : prototype) {

				cout << sprintf(string(n++, '\r') + option.first, option.second);

			}

			cout << BRAKETCLOSE << endl;

		}

		string sprintf(string key, Any* value) {

			return key + ":id";

		}

};

#endif

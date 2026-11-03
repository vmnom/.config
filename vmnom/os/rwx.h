#ifndef RWX_H
#define RWX_H

#include <index.h>

struct protocol : map<string, Nosql*> {};

struct Nosql : protocol {

	protected:

		string fd;

		Nosql(int ignored);

	public:

		Nosql(string value = "{}") {
			fd = value;
		}

	public:

		Nosql* prototype;

		Nosql* init (Nosql* empty) {

			prototype = empty;

		}

		Nosql* option (string key, Nosql value) {

			(*this)[key] = &value;

			return this;
		}

		Nosql* assign (string key, Nosql* value) {

			(*this)[key] = value;

			return this;
		}

		Nosql* options (string key) {

			return (*this)[key];

		}

		void valueOf (Nosql* prototype) {

			cout << "prototype" << endl;

		}

};

struct playground : Nosql {

	void user(string addr, int port) {

		init(this);

		prototype->option("mail", {"mail"});

		prototype->option("user", {"user"});

		prototype->option("mail2", {"mail2"});

		prototype->assign("mail2", prototype);

		valueOf(options("mail"));
	}

};

#endif

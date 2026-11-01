#ifndef RWX_H
#define RWX_H

#include <index.h>
#include <typeinfo>

class protocol : map<string, Any*> {

	public:

		Any* options(string key);

		Any* option(string key, Any value);
};

struct nosql {

	Any*	prototype;

};

struct Any : public protocol {

	public:

		Nosql	prototype;
		String	text;
		Double	number;

		Any(string value) {
			text = {value};
		}

		Any(double value) {
			number = {value};
		}

		Any(nosql value) {
			prototype = {&value};
		}

	public:



		void valueOf() {
			cout << typeid(this).name() << endl;
		}
		
		Any* clone() {
			return this;
		}

};

struct playground {

	Any	window;

	const void listen(const string addr, const int port) {
		window.option("addr", {addr});
		window.option("port", {port});
	}

	const void init() {
		window.options("port")->valueOf();
	}

};

inline Any* protocol::options(string key) {
	return (*this)[key];
}

inline Any* protocol::option(string key, Any value) {

	(*this)[key] = &value;

	return protocol::options(key);

}

#endif

#ifndef RWX_H
#define RWX_H

#include <nosql.h>

struct create : nosql {

	void verify() {

		cout << "database ready." << endl;

	}

};

#endif

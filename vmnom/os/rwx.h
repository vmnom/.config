#ifndef RWX_H
#define RWX_H

#include "include/plugins/nosql.h"

struct playground : nosql {

	host sql;

	map<string, host> fields;

	void subscribe(string file) {

		options(fields);

	};

};

#endif

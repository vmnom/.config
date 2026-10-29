#ifndef RWX_H
#define RWX_H

#include "include/plugins/nosql.h"

struct playground;

struct playground : nosql {

	signal sql;

	map<string, signal> servers;

	map<string, signal> models;

	map<string, signal> hosts;

	void index(string file) {

		this->sql(this, file);

		subscribe(servers);
		subscribe(models);
		subscribe(hosts);

	};
};

#endif

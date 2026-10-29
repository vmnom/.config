#ifndef RWX_H
#define RWX_H

#include "include/plugins/nosql.h"

struct playground : nosql {

	signal sql;

	signal backups;

	map<string, signal> hosts;

	map<string, signal> models;

	map<string, signal> servers;

	void index(string file) {

		this->sql(this, file);

		subscribe(hosts);
		subscribe(models);
		subscribe(servers);

	};
};

#endif

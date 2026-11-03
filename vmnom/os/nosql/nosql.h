#ifndef NOSQL_H
#define NOSQL_H

#include <map>
#include <string>
#include <iostream>

struct Nosql;

using namespace std;

/*
 * storage
 */

struct protocol : map<string, Nosql*> {

};

#endif

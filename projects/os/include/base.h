#ifndef BASE_H
#define BASE_H

/****
 *
 * Registered application routes.
 */

struct router {
	int value;
};

typedef router* routes;

using map = void (*)();

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <iostream>

#endif

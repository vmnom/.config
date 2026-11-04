/*
 * main.cc
 *
 */

#include <nosql.h>

int main(int _, char* __[]) {

	Nosql eml(0);

	string source = eml.mail();

	cout << source;

	return 0;

};

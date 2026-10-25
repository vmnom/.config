#include <rwx.h>

int main(int argc, char* argv[]) {

	/*
	 * define
	 */

	playground rwx;

	/*
	 * httpd
	 *
	 */

	rwx.host = [] (router* routes) {

		nosql vmnom = routes->group("vmnom");

	};

	/*
	 * vmnom, llc
	 *
	 */

	auto c = [] (playground* rwx) {

		rwx->cls();

		rwx->enable(HTTP);

		rwx->console("vmnom.1.0.0-nosql$ ");

	};

	return	c(&rwx);

};

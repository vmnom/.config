#include <rwx.h>

int main(int argc, char* argv[]) {

	/*
	 * define
	 *
	 */

	playground rwx;

	/*
	 * httpd
	 *
	 */

	rwx.routes = [] (router* routes) {

		// some routes

	};

	/*
	 * console tty
	 *
	 */

	auto terminal = [] (playground* rwx) {

		rwx->clear();

		rwx->console("vmnom.1.0.0-nosql");

		rwx->plug(HTTP);

	};

	return	terminal(&rwx);

};

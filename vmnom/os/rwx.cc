#include <rwx.h>

int main(int argc, char* argv[]) {

	/*
	 * definitions.
	 *
	 */

	playground rwx;

	/*
	 * implementations.
	 *
	 */

	auto register = [] (playground* rwx) {

		rwx->cls();

		rwx->enable(HTTP);

		rwx->console("vmnom.1.0.0-nosql$ ");

	};

	/*
	 * routes list.
	 *
	 */

	rwx.host["default"] = [] (router* routes) {};

	return	register(&rwx);

};

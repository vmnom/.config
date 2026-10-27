#include <rwx.h>

int main(int argc, char* argv[]) {

	playground rwx;

	/* 
	 * create hosts 
	 *
	 *-*/

	rwx.hosts["default"] = [] (nosql id) {

	}

	rwx.verify(80);

	return EXIT_FAILURE;
};

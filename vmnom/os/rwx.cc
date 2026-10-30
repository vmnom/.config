#include <rwx.h>

playground rwx;

int main(int argc, char* argv[]) {

	/*
	 *
	 *
	 */

	rwx.assign("user", "okok");

	/*
	 *
	 */

	rwx.select("user")->assign("id", "0");

	/*
	 *
	 *
	 */

	rwx.valueOf();

	/*
	 *
	 *
	 */

	return 0;

};

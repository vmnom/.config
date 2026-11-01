#include <rwx.h>

using namespace std;

playground rwx = {0};

int main(int argc, char* argv[]) {

	/*
	 * httpd
	 *
	 **/

	rwx.listen("::", 80);

	/*
	 *
	 */

	rwx.init();


	return 0;

};

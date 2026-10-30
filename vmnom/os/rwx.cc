#include <rwx.h>

int main(int argc, char* argv[]) {

	playground rwx;

	rwx.up("rwx/private/cpu");

	rwx.verify();

	return 0;
};

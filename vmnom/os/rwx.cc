#include <rwx.h>

int main(int argc, char* argv[]) {

	playground rwx = {0};

	rwx.listen("::", 80);

	return 0;

};

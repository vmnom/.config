#ifndef RWX_H
#define RWX_H

#include <index.h>

struct playground {

	Any window;

	void listen(string addr, int port) {

		window.option("a", addr);

		window.option("b", addr);

		window.option("c", addr);

/* 		window.option("port", port); */

/* 		Any console = {0}; */

/* 		console.option("log", {"text here"}); */

/* 		window.option("console", console); */

		window.log();

	}

};

#endif

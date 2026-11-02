#ifndef RWX_H
#define RWX_H

#include <index.h>

struct playground {

	Any window;

	void listen(string addr, int port) {

		window.option("name", {"username"});

		window.option("email", {"mail@gmail.com"});

/* 		window.option("b", addr); */

/* 		window.option("c", addr); */

/* 		Any console(0); */

/* 		console.option("log", {"alert"}); */

/* 		window.option("console", {console}); */

/* 		window.option("port", port); */

		Any log = {0};

		/* log.option("msg", {"text here"}); */

		/* window.assign("console", &log); */

		cout << window.valueOf();

	}

};

#endif

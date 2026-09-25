#include <rwx.h>

extern "C" void service (kernel* ctrl) {

	/*
	 *
	 *
	 */

	router routes = ctrl.group("vmnom.com")->router(sdl{

			.redirect = ()
	});

	auto onClick = [] (request req) JSON {

	}

	browser(https:://::/users/create)

	routes->get("users/create", index, view{"login"});

	fetch()

	routes->post("users/create", login, view{"dashboard"});
};



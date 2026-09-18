#include <base.h>

Scope map(Entity *use) {

	{
		Router routes = use.Router;
	}

	Response login(Request req) 
	{
		return Raw("{'json': 'error'}");
	}

	router.define(login);

	return EXIT_FAILURE;
};

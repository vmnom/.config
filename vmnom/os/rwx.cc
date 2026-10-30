#include <rwx.h>

playground rwx;

int main(int argc, char* argv[]) {

	/**
	 * sqlite
	 *
	 */

	rwx.sql = [] (nosql* nosql, string _) {

		const char* sql =
			"CREATE TABLE IF NOT EXISTS connections ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"packet JSON,"
			"readonly BOOLEAN NOT NULL DEFAULT 0,"
			"created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP"
			");";

		/* nosql->query(sql); */

	};

	/**
	 * options
	 *
	 */

	rwx.fields["server"] = [] (nosql* nosql, string key) {

		nosql->option(key)->put("id", "32");

	};

	/**
	 * playground.
	 *
	 */

	rwx.subscribe("usr/private/memory");

	/*
	 *
	 **/

	return EXIT_SUCCESS;

};

#include <rwx.h>

playground rwx;

int main(int argc, char* argv[]) {

	/**
	 * server
	 *
	 */

	rwx.servers["http"] = [] (nosql* nosql, string key) {

	};

	/**
	 * sqlite 
	 *
	 */

	rwx.sql = [] (nosql* nosql, string _) {

		const char* sql =
			"CREATE TABLE IF NOT EXISTS connections ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"readonly BOOLEAN NOT NULL DEFAULT 0,"
			"packet JSON,"
			"created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP"
			");";

		nosql->query(sql);

	};

	/**
	 * playground.
	 *
	 */

	rwx.index("usr/private/memory");


	return EXIT_SUCCESS;

};

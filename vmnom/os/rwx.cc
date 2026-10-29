#include <rwx.h>

playground rwx;

int main(int argc, char* argv[]) {

	/**
	 * sqlite engine, readonly.
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

		nosql->query(sql);

	};

	/**
	 * groups
	 *
	 */

	rwx.hosts["*"] = [] (nosql* nosql, string key) {

		cout << "ready" << endl;

	};


	/**
	 * playground.
	 *
	 */

	rwx.index("usr/private/memory");

	return EXIT_SUCCESS;

};

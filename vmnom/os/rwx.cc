#include <rwx.h>

playground rwx;

int main(int argc, char* argv[]) {

	/**
	 * sqlite 
	 *
	 */

	rwx.select("usr/private/memory");

	/**
	 * create hosts 
	 *
	 */

	rwx.sql = [] (playground* nosql) {

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

	rwx.pay();


	return EXIT_SUCCESS;

};

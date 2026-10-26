#include <plugins.h>

struct utils {

	string buffer;

};

struct database : utils {

	void xsstest() {

		load();

		verify();

	}

	sqlite3 *db = NULL;

	sqlite3_stmt *stmt = NULL;

	void load() {

		if (sqlite3_open("rwx/private/cpu", &db) != SQLITE_OK) {
			fprintf(stderr, "Open error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}

	}

	void verify() {

		const char *sql =
			"CREATE TABLE IF NOT EXISTS leads ("
			"id TEXT PRIMARY KEY,"
			"data TEXT NOT NULL CHECK(json_valid(data))"
			");";

		cout << query(sql) << endl;

	}

	string query(const char *sql) {

		char *err = NULL;

		int rc = sqlite3_exec(db, sql, NULL, NULL, &err);

		if (rc == SQLITE_OK) {

			return "OK";
		}

		printf("Error message: %s\n", err ? err : "Unknown error");

		string error_str(err);

		return "ERROR: " + error_str;
	}

};

struct nosql : database {};

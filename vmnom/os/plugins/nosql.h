#include <plugins.h>

struct Q {

	const char *create_trigger_sql =
		"CREATE TRIGGER IF NOT EXISTS leads"
		"AFTER INSERT ON json_data"
		"WHEN NEW.created_at IS NULL"
		"BEGIN"
		"	UPDATE json_data"
		"	SET created_at = datetime('now')"
		"	WHERE id = NEW.id;"
		"END;";

	const char *create_table_sql =
		"CREATE TABLE IF NOT EXISTS leads ("
		"id TEXT PRIMARY KEY,"
		"json TEXT NOT NULL CHECK(json_valid(data)),"
		"registred BOOLEAN NOT NULL DEFAULT 0,"
		"created_at TEXT"
		");";

	const char *item =
		"INSERT INTO json_data (id, registred, data)"
		"VALUES (?1, ?2);";

	const char *drop = "DELETE FROM leads WHERE registred = 0;";

};

struct database : Q {

	using Error = string;

	sqlite3 *db = nullptr;

	sqlite3_stmt *stmt = nullptr;

	void hold(string json) {

		int rc = sqlite3_prepare_v2(db, item, -1, &stmt, NULL);

		if (rc == SQLITE_OK) {

			sqlite3_bind_text(stmt, 1, "func_add", -1, SQLITE_STATIC);

			sqlite3_bind_int(stmt, 2, 0);

			sqlite3_bind_text(
					stmt, 3,
					json.c_str(),
					static_cast<int>(json.size()),
					SQLITE_TRANSIENT
					);

			int rc = sqlite3_step(stmt);

			if (rc != SQLITE_DONE)
				fprintf(stderr, "Insert error: %s\n", sqlite3_errmsg(db));

			sqlite3_finalize(stmt);
		}
	}

	void open() {

		if (sqlite3_open("rwx/private/cpu", &db) != SQLITE_OK) {
			fprintf(stderr, "Open error: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
		}

	}

	Error query(const char *sql) {

		char *err = NULL;

		int rc = sqlite3_exec(db, sql, NULL, NULL, &err);

		if (rc == SQLITE_OK) {

			return "OK";
		}

		string error(err);

		return "ERROR: " + error;

	}

	void up() {

		open();

		query(create_table_sql);

		query(create_trigger_sql);

	}

};

struct nosql : database {

	void findOrCreat(string json) {
	}

}

struct srv : nosql {

	void connected(string json) {

		findOrCreate(json);

	}

}


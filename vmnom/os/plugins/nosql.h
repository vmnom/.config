struct Query {

	sqlite3 *db = NULL;

	sqlite3_stmt *stmt = NULL;

	const char *create_table_sql =
		"CREATE TABLE IF NOT EXISTS leads ("
		"id TEXT PRIMARY KEY,"
		"data TEXT NOT NULL CHECK(json_valid(data)),"
		"readonly BOOLEAN NOT NULL DEFAULT 0,"
		"created TEXT"
		");";

	const char *create_trigger_sql =
		"CREATE TRIGGER IF NOT EXISTS leads"
		"AFTER INSERT ON leads"
		"WHEN created IS NULL"
		"BEGIN"
		"	UPDATE leads"
		/* "	SET created = datetime('now')" */
		"	WHERE id = NEW.id;"
		"END;";

	const char *item =
		"INSERT INTO leads (data, creation)"
		"VALUES (?1, ?2);";

	const char *drop = "DELETE FROM leads WHERE registred = 0;";

};

struct database : Query {

	string hold(string json) {

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

			sqlite3_finalize(stmt);

			if (rc != SQLITE_DONE)
				return "ERROR";
		}

		return "OK";
	}

	string open(string file) {

		if (sqlite3_open(file.c_str(), &db) != SQLITE_OK) {

			sqlite3_close(db);

			return "error opening database.";

		}

		return "OK";
	}

	string query(const char *sql) {

		char *err = NULL;

		int rc = sqlite3_exec(db, sql, NULL, NULL, &err);

		if (rc == SQLITE_OK) {

			return "OK";
		}

		string error(err);

		return "QUERY: " + error;

	}

	void up(string file) {

		cout << open(file) << endl;

		cout << query(create_table_sql) << endl;

		cout << query(create_trigger_sql) << endl;

	}

};

struct nosql : database {};

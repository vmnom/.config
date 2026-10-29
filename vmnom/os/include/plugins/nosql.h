struct nosql;
struct database;
struct prototype;

struct q {

	sqlite3 *db;

	sqlite3_stmt *stmt;

	const char *create_trigger_sql;

	const char *create_connections_sql;

};

struct database : q, console  {

	const char *drop;

	const char *insert;

	void begin(string file) {

		select(file);

		query(create_connections_sql);

	}

	void select(string file) {

		if (sqlite3_open(file.c_str(), &db) != SQLITE_OK) {

			sqlite3_close(db);

			log("error_sql");

		}

		else log("ok");

	}

	void query(const char *sql) {

		char *err = NULL;

		int rc = sqlite3_exec(db, sql, NULL, NULL, &err);

		if (rc != SQLITE_OK) {

			/* string error(err); */

			log("error_sql");

		}

		else log("ok");

	}

	/* string store(string json) { */

	/* 	int rc = sqlite3_prepare_v2(db, insert, -1, &stmt, NULL); */

	/* 	if (rc == SQLITE_OK) { */

	/* 		sqlite3_bind_text(stmt, 1, "func_add", -1, SQLITE_STATIC); */

	/* 		sqlite3_bind_int(stmt, 2, 0); */

	/* 		sqlite3_bind_text( */
	/* 				stmt, 3, */
	/* 				json.c_str(), */
	/* 				static_cast<int>(json.size()), */
	/* 				SQLITE_TRANSIENT */
	/* 				); */

	/* 		int rc = sqlite3_step(stmt); */

	/* 		sqlite3_finalize(stmt); */

	/* 		if (rc != SQLITE_DONE) */

	/* 			log("error_sql"); */
	/* 	} */

	/* 	log("ok"); */
	/* } */

	void sql(string file) {

		create_connections_sql = 

			"select * from connections;";

		begin(file);

	}
};

struct prototype : map<string, nosql*> {

	void set(string key, nosql* value) {

		(*this)[key] = value;

	}

	nosql* get(string key) {

		return (*this)[key];

	}

};

struct nosql : prototype, database {

	string innerText;

	prototype prototype;

	string (*serialize) (nosql*);
};

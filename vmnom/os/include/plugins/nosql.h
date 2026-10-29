#include <sqlite3.h>

struct nosql;
struct database;
struct prototype;

typedef void (*signal) (nosql*, string);

struct q {

	string src;

	sqlite3 *db;

	sqlite3_stmt *stmt;

};

struct database : q, console  {

	const char *drop;

	void select(string file) {

		if (sqlite3_open(file.c_str(), &db) != SQLITE_OK) {

			sqlite3_close(db);

			log("src:open:error");

		}

		else log("src::open");

	}

	void query(const char *sql) {

		char *err = NULL;

		int rc = sqlite3_exec(db, sql, NULL, NULL, &err);

		if (rc != SQLITE_OK) {

			/* string error(err); */

			log("src::query::error_sql");

		}

		else log("src::query");

	}

};

struct validator {

	vector<string> e;

	bool fail() {
		return e.empty();
	}

	void flush() {
		e.clear();
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

	void subscribe(map<string, signal> service) {

		map<string, signal>::iterator it;

		for (it = service.begin(); it != service.end(); ++it) {
			it->second(this, it->first);
		}

	}

};

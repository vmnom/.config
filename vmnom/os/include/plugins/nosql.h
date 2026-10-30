#include <sqlite3.h>

struct prototype;
struct database;
struct nosql;

typedef void (*host) (nosql*, string);

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

struct prototype : map<string, nosql*> {

	void resolve(string key, nosql* value) {

		(*this)[key] = value;

	}

	nosql* promise(string key) {

		return (*this)[key];

	}

};

struct nosql : database {

	string innerText;

	prototype prototype;

	nosql* option(string option) {

		prototype.resolve(option, this);

		return prototype.promise(option);

	}

	void put(string key, string text) {

		option(key)->value(text);
	}

	void value(string value) {

		innerText = value;

	}

	void options(map<string, host> service) {

		map<string, host>::iterator it;

		for (it = service.begin(); it != service.end(); ++it) {
			it->second(this, it->first);
		}

	}
};

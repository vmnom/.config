#include <nosql.h>

int main(int argc, char* argv[]) {

	string json = R"({
	  "kind": "FunctionDecl",
	  "name": "add",
	  "inner": [
	    {
	      "kind": "ParmVarDecl",
	      "name": "a"
	    },
	    {
	      "kind": "ParmVarDecl",
	      "name": { "id": { "xyz": "nice" } }
	    }
	  ]
	})";

	nosql rwx = {json};

	rwx.xsstest();

	return	EXIT_FAILURE;

};


#include <plugins.h>

int main(int argc, char* argv[]) {

	// create rwx; 

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

	// rwx.verify();
	
	cout << json << endl;

	return	EXIT_FAILURE;

};

bin:
	clear
	time c++ -std=c++17 -include-pch rwx/gch -H -O0 -pipe -Ios -Ios/plugins os/rwx.cc -o rwx/bin -lsqlite3
	rwx/bin || true

pch:
	time c++ -std=c++17 -H -O0 -pipe -x c++-header -Ios/plugins os/rwx.h -o rwx/gch
	clear
	time make || true

git: 
	git add ..
	git commit -m "rwx"
	git push --all || true

debug:
	@clear
	@git ls-files "*.cc" "*.h"

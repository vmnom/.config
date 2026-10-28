bin:
	time c++ -std=gnu++98 -Winvalid-pch -Irwx -H -pipe -Ios os/rwx.cc -o rwx/bin -lsqlite3
	rwx/bin

pch:
	clear
	time c++ -std=gnu++98 -H -pipe -x c++-header os/include/index.h -o rwx/index.h.gch
	ctags -R .
	git ls-files "*.cc" "*.h"

git: 
	git add ..
	git commit -m "rwx"
	git push --all

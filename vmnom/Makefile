man:
	clear
	time g++ -std=gnu++98 -H -pipe -Ios -Ios/plugins os/rwx.cc -o rwx/bin -lsqlite3
	rwx/bin
pch:
	ctags -R .
	g++ -std=gnu++98 -H -O0 -pipe -x c++-header -Ios/plugins os/rwx.h
	clear
	make

git: 
	git add ..
	git commit -m "rwx"
	git push --all

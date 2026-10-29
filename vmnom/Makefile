SHELL := /bin/zsh

PCH := rwx/index.h.pch

Compile := c++ -include-pch $(PCH) -std=c++98 -H -pipe -Ios os/rwx.cc -o rwx/bin -lsqlite3 -Winvalid-pch -Irwx

CompilePCH := time c++ -std=c++98 -H -pipe -x c++-header os/include/index.h -o $(PCH) 

dev:
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nplug\t%J...\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(Compile)'
	@echo
	rwx/bin
	@echo

pch:
	rm -rf rwx/index.h.*
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nplug\t%J...\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CompilePCH)'
	@echo

git: 
	git add ..
	git commit -m "rwx"
	git push --all

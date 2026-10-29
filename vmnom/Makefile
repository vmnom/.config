PCH := rwx/index.h.gch

Compile := clang -include-pch $(PCH) -std=c++98 -Ios os/rwx.cc -o rwx/bin -lsqlite3 -H -pipe 

CompilePCH := clang -std=c++98 -pipe -x c++-header os/include/index.h -o $(PCH) 

dev:
	clear
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nlang\t[\033[38;5;208m\"%J...\"\033[0m]\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(Compile)'
	rwx/bin
	@echo

pch:
	clear
	@rm -rf rwx/index.h.* || true
	@echo "[$(PCH)]"
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nlang\t[\033[38;5;208m\"%J...\"\033[0m]\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CompilePCH)'
	@echo

git: 
	git add ..
	git commit -m "rwx"
	git push --all
	@echo

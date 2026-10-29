SHELL := $(shell echo $$SHELL)

CC := c++ -std=c++98

PCH := rwx/index.h.gch

compile_dev := -include-pch $(PCH)  -Ios os/rwx.cc -o rwx/bin -lsqlite3 -H -pipe 

compile_pch := -pipe -x c++-header os/include/index.h -o $(PCH) 

dev:
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CC) $(compile_dev)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CC) $(compile_dev)'
	@echo
	rwx/bin
	@echo

pch:
	@echo
	@rm -rf rwx/index.h.* > /dev/null
	@echo "[!$(PCH)] compiling...."
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CC) $(compile_pch)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CC) $(compile_pch)'
	@echo

git: 
	@echo
	git add ..
	git commit -m "rwx"
	git push --all
	@echo

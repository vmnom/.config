SHELL := $(shell echo $$SHELL)
CC := clang++ -std=c++20
PCH := rwx/index.h.gch
compile_dev :=  -include-pch rwx/index.h.gch -lsqlite3 -Ios os/rwx.cc -o rwx/bin 
compile_pch := -x c++-header os/include/index.h -o $(PCH) 

dev:
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CC) $(compile_dev)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CC) $(compile_dev)'
	@echo
	rwx/bin
	@echo

pch:
	@echo
	@echo "[!$(PCH)] compiling...."
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CC) $(compile_pch)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CC) $(compile_pch)'
	@echo

git: 
	@echo "git add ../"
	@if [ -n "$$(git status --porcelain)" ]; then \
		git add -A && git commit -m "rwx"; \
	fi
	git push --all
	@echo

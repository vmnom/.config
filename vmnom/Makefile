CLANG   := c++ -std=c++17
VMNOM   := usr/bin/vmnom
CFLAG   := -w -pipe
SHELL   := $(shell echo $$SHELL)
cdev    := $(CFLAG) -lsqlite3 -Ios -Ios/nosql os/rwx.cc -o $(VMNOM) 
cpch    := $(CFLAG) -x c++-header os/include/index.h

dev:
	@echo
	@echo "[$(VMNOM)] compiling...."
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'$(CLANG) $(cdev)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo

pch:
	@echo
	@echo "[index.h.gch] compiling...."
	@echo
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'$(CLANG) $(cpch)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cpch)'
	@echo

git: 
	@echo
	@echo "git add .."
	@if [ -n "$$(git status --porcelain)" ]; then \
		git add -A && git commit -m "rwx"; \
	fi
	git push --all
	@echo
	@git count-objects -vH

CLANG   := c++
CMAKE   := -std=c++98
VMNOM   := usr/bin/vmnom
CFLAG   := -w -H -pipe
CPCH    := -include/root/.config/vmnom/os/nosql/index.h
SHELL   := $(shell echo $$SHELL)
cdev    := $(CMAKE) $(CFLAG) -lsqlite3 $(CPCH) -Ios/nosql -Ios os/rwx.cc -o $(VMNOM) 
cpch    := $(CMAKE) $(CFLAG) -O0 -x c++-header os/nosql/index.h

dev:
	@echo
	@echo "[$(VMNOM)] compiling...."
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'$(CLANG) $(cdev)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo

pch98:
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

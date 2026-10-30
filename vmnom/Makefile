CFLAG   := -O0 -pipe -w
CLANG   := c++ -std=c++11
VMNOM   := usr/bin/vmnom
SHELL   := $(shell echo $$SHELL)
cdev    := $(CFLAG) -include os/include/index.h -Ios os/rwx.cc -o $(VMNOM) -lsqlite3
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

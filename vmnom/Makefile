VMNOM   := usr/bin/vmnom
CLANG   := c++
CMAKE   := -std=c++11
CFLAG   := -w -H -pipe
SHELL   := $(shell echo $$SHELL)
CPCH    := -include./os/nosql/nosql.h
SOURCE   := main.cc
HEADERS  := -lsqlite3
HEADERS  += -Ios/nosql

cpch    := $(CMAKE) $(CFLAG) -O0 -x c++-header os/nosql/nosql.h
cdev    := $(CMAKE) $(CFLAG) $(CPCH) $(HEADERS) $(SOURCE) -o $(VMNOM) 

cc:
	@echo
	@echo "[$(VMNOM)] compiling...."
	@echo
	$(SHELL) -c 'TIMEFMT=$$'"'"'$(CLANG) $(cdev)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo

pch:
	@echo
	@echo "[index.h.gch] compiling...."
	@echo
	@echo
	$(SHELL) -c 'TIMEFMT=$$'"'"'$(CLANG) $(cpch)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cpch)'
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

dev:
	make pch
	make

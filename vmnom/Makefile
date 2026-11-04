VMNOM   := local/bin/vmnomx
CLANG   := time c++
CMAKE   := -std=c++98
CFLAG   := -w -H -pipe
SHELL   := $(shell echo $$SHELL)
CPCH    := -include./os/nosql/index.h
SOURCE   := main.cc
HEADERS  := -lsqlite3
HEADERS  += -Ios
HEADERS  += -Ios/nosql

cpch    := $(CMAKE) $(CFLAG) -O0 -x c++-header os/nosql/index.h
cdev    := $(CMAKE) $(CFLAG) $(HEADERS) $(CPCH) $(SOURCE) -o $(VMNOM)

cc:
	@echo
	@echo "[$(VMNOM)] compiling...."
	@echo
	@$(SHELL) -c '$(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo

pch:
	@echo
	@echo "[nosql.h.gch] compiling...."
	@echo
	@echo
	@$(SHELL) -c 'time $(CLANG) $(cpch)'
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
	@rm -rf os/nosql/nosql.h.gch

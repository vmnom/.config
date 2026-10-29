CFLAG   := -pipe
CLANG   := clang++ -std=c++98
VMNOM   := rwx/vmnomxyz
SHELL   := $(shell echo $$SHELL)
cdev    := $(CFLAG) -include os/include/index.h -lsqlite3 -Ios os/rwx.cc -o $(VMNOM)
cpch    := $(CFLAG) -x c++-header os/include/index.h


dev:
	@echo
	@echo "[$(VMNOM)] compiling...."
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\n$(CLANG) $(cdev)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo
pch:
	@echo
	@echo "[index.h.gch] compiling...."
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\n$(CLANG) $(cpch)\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cpch)'
	@echo
git: 
	@echo
	@echo "git add .."
	@if [ -n "$$(git status --porcelain)" ]; then \
		git add -A && git commit -m "rwx"; \
	fi
	git push --all
	@echo

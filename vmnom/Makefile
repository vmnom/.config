CFLAG   := -H
CLANG   := c++ -std=c++98
VMNOM   := rwx/vmnomxyz
SHELL   := $(shell echo $$SHELL)
PCH     := rwx/index.h.gch
cdev    := $(CFLAG) -include os/include/index.h -Ios os/rwx.cc -o $(VMNOM) -lsqlite3
cpch    := $(CFLAG) -x c++-header os/include/index.h

dev:
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CLANG) $(cdev)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cdev)'
	@echo
	$(VMNOM)
	@echo
pch:
	@echo
	@echo "[!$(PCH)] compiling...."
	@echo
	@$(SHELL) -c 'TIMEFMT=$$'"'"'\nexec\t\033[38;5;208m$(CLANG) $(cdev)\033[0m\n\nreal\t%E\ncput\t%U\nsystem\t%S'"'"'; time $(CLANG) $(cpch)'
	@echo
git: 
	@echo "git add .."
	@if [ -n "$$(git status --porcelain)" ]; then \
		git add -A && git commit -m "rwx"; \
	fi
	git push --all
	@echo

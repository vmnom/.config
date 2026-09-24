CXX    := /usr/bin/clang++

CFLAGS := -std=c++17 

FILES = $(wildcard os/apps/*.cc)

auto:
	@rm -rf public/vendor/*
	@for file in $(FILES); do \
		time $(CXX) $(CFLAGS) -shared -fPIC -Ios "$$file" -o "public/vendor/$$(uuidgen).dlyb"; \
	done
	@echo
	@$(CXX) $(CFLAGS) -Ios os/rwx.cc -o public/vmnom
	public/vmnom

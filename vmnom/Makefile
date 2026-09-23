FILES = $(wildcard os/apps/*.cc)

COMPILER := c++ -std=c++17

auto:
	rm -rf public/vendor/*
	for file in $(FILES); do \
		$(COMPILER) -shared -fPIC -Ios "$$file" -o "public/vendor/$$(uuidgen).dlyb"; \
	done
	$(COMPILER) -Ios os/rwx.cc -o /usr/bin/vmnom

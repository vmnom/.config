FILES = $(wildcard os/apps/controllers/*.cc)

auto:
	@rm -rf public/vendor/*
	@for file in $(FILES); do \
		clang++ -shared -fPIC -Ios/include "$$file" -o "public/vendor/$$(uuidgen).dlyb"; \
	done
	@g++ -std=c++17 -Ios/include os/apps/base.cc -o public/kernel

# gzsize

CC        ?= gcc
PREFIX    ?= /usr/local
BINPREFIX ?= $(PREFIX)/bin
MANPREFIX ?= $(PREFIX)/share/man/man1

SRC:=src
TESTS_RUNNER=./test/test.sh

SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

MANS=$(wildcard man/*.md)
MAN_PAGES=$(MANS:.md=.1)

BIN:=gzsize

CFLAGS=-Wall -Wextra -Wundef -Wpointer-arith -std=gnu99
LDFLAGS=-lz

CPPCHECK_VER:=$(shell cppcheck --version 2>/dev/null)
ifdef CPPCHECK_VER
CPPCHECK=cppcheck -q \
	--enable=warning,style,performance \
	--std=c99 \
	--language=c
else
CPPCHECK=\#
endif

.PHONY: test

all: $(BIN) docs

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

docs: $(MAN_PAGES)

man/%.1: man/%.md
	ronn -rw --manual "GZSize Manual" --pipe $< > $@

man/%.html: man/%.md
	ronn -w5 -s toc --manual "GZSize Manual" --pipe $< > $@

clean:
	find . -name '*.o' -delete
	rm -f $(BIN)
	rm -rf *.tmp
	rm -f man/*.1

test: $(BIN)
	@# avoid a failed build because cppcheck doesn't exist or is a wrong
	@# version
	$(CPPCHECK) $(SRC) || true
	@GZSIZE=$${PWD}/$(BIN) $(TESTS_RUNNER)

test-install:
	@# this is used on CI server. 'gzsize' has been installed just before so
	@# we don't have to depend on the 'install' target here.
	@GZSIZE=$(BINPREFIX)/$(BIN) $(TESTS_RUNNER)

install: $(BIN) docs
	@mkdir -p $(BINPREFIX)
	@mkdir -p $(MANPREFIX)
	cp -f $(BIN) $(BINPREFIX)/$(BIN)
	cp -f man/*.1 $(MANPREFIX)/

uninstall:
	rm -f $(BINPREFIX)/$(BIN)
	$(foreach MAN, $(MAN_PAGES), \
		rm -f $(MANPREFIX)/$(notdir $(MAN)))

ghpages:
	@# adapted from https://github.com/ddollar/foreman workflow
	make man/$(BIN).html
	cp man/$(BIN).html /tmp/
	git stash
	git checkout gh-pages
	mv /tmp/$(BIN).html index.html
	git add index.html
	git commit -m "saving man page to GitHub docs"
	git push origin gh-pages
	git checkout master
	git stash pop || true

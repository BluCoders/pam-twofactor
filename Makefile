CC=gcc
CFLAGS=-O3 -march=native -Wall -Werror -Wextra -fPIC
LDFLAGS=-shared
LDLIBS=-lpam

.PHONY: all clean

all: pam_twofactor.so

clean:
	rm -rf *.so *.o

pam_twofactor.so: pam_twofactor.o

%.so: %.o
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

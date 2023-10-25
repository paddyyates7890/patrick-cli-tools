CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o, $(SOURCES))

TARGET=build/clitools.a
SO_TARGET=$(patsubst %.a, %, $(TARGET))

all: $(TARGET) $(SO_TARGET)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	cc -o $@ $(OBJECTS)


build:
	@mkdir -p build
	@cp help.txt build/
	@cp scripts.txt build/

clean:
	rm -rf build $(objects)

BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'

check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true



CC=g++ 
CFLAGS=-std=c++11 -I.
EXEUTABLE=fluid
OBJECTS=fluid.o main.o

HEADERS=fluid.h vector3.h
SOURCES=fluid.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: $(EXEUTABLE)

$(EXEUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

fluid.o: fluid.h vector3.h
main.o: fluid.h vector3.h

.PHONY: clean
clean:
	rm -rf *.o $(EXEUTABLE)
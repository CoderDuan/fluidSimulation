CC=g++ -std=c++11
CFLAGS=-o
EXEUTABLE=fluid

HEADERS=*.h
SOURCES=*.cpp

$(EXEUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(EXEUTABLE) $(SOURCES)

.PHONY: clean
clean:
	rm -rf *.o $(EXEUTABLE)
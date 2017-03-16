CC=g++ -std=c++11
CFLAGS=-o
EXEUTABLE=fluid

HEADERS=*.h
SOURCES=*.cpp

$(EXEUTABLE): $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) $(EXEUTABLE) $(HEADERS) $(SOURCES)

.PHONY: clean
clean:
	rm -rf *.o $(EXEUTABLE)
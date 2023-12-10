CC=g++
CFLAGS=-g -Wall -Werror -std=c++17 -Wextra
LDFLAGS=-lpthread
SOURCES=test_list.cc facade.cc text_file_handler.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=test

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)
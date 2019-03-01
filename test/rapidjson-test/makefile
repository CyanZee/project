CC	= g++
LIB_DIR = ../lib
INCLUDES= -I ../../include/
CFLAGS  = -Wall -ggdb -std=c++11
LIBS	= -L $(LIB_DIR) -lpthread -Wl,-rpath=./:../lib

OBJS	= main.o config.o

TARGET 	= main

all:$(TARGET)

main:./main.o $(OBJS)
	$(CC) -g -o $@ $^ $(INCLUDES) $(LIBS)

%.o:%.cpp
	$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

.PHONY:
clean:
	rm -f $(TARGET) *.o


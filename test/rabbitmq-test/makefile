CC     = g++

VPATH    = ../../src
LIB_DIR  = -L ../../lib 
INCLUDES = -I ../../include -I ../../src 
CFLAGS   = -Wall -g -std=c++11 
LIBS     = -lpthread `pkg-config --libs libSimpleAmqpClient` `pkg-config --libs librabbitmq`

OBJS    = rabbitmq.o

TARGET  = main

all:$(TARGET)

main:main.o $(OBJS)
	$(CC) -o $@ $^ $(INCLUDES) $(LIBS)

%.o:%.c
	$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

%.d:%.c
	@set -e; $(CC) -MM $< $(INCLUDES) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.o:%.cpp
	$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

%.d:%.cpp
	@set -e; $(CC) -MM $< $(INCLUDES) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
			
sinclude $(OBJS:.o=.d)

.PHONY:
clean:
	rm -f $(TARGET) *.o *.d *.d.* 
install:$(TARGET)
	cp $(TARGET) $(INSTALL_DIR)

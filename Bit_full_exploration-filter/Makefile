CC = g++
CFLAGS = -Wall -static
TARGET = Bit
SRCS = Bit.cpp
OBJS = $(SRCS:%.cpp=%.o)
LIBDIR = -IC:\MinGW\bin
LIBS = stdc++

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

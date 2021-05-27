#Elizabeth Willard ECE331 Lab 2 2/24/2020 This is a makefile for the MMULT program 
TARGET = mmult
OBJS = main.o mmult.o
CFLAGS = -Wall -g
LIBS = -lm

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS) core*

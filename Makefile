CC = g++

CXXFLAGS = -Wall

TARGET = beatpi

LIBS = -lwiringPi

SRCDIR = src

SRCS =	$(SRCDIR)/main.cpp

OBJS = $(SRCS:.cpp=.o)

### Rules

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(TARGET)

re: fclean all

.PHONY: all clean fclean re
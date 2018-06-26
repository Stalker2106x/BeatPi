CC = g++

CXXFLAGS = -Wall -Ithirdparty -Iinclude

TARGET = beatpi

LIBS = -lwiringPi

SRCDIR = src

SRCS =	$(SRCDIR)/main.cpp		\
	$(SRCDIR)/Controller.cpp	

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

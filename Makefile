CC = g++

CXXFLAGS = -Wall -Ithirdparty -Iinclude

TARGET = beatpi

LIBS = -lwiringPi -lmicrohttpd

SRCDIR = src

SRCS =	$(SRCDIR)/main.cpp		\
	$(SRCDIR)/Button.cpp		\
	$(SRCDIR)/Controller.cpp	\
	$(SRCDIR)/Httpd.cpp

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

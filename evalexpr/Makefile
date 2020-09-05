NAME = evalexpr

CC = gcc

CFLAGS = -c -Wall -Wextra 

LDFLAGS = -Wall -Wextra 

SOURCES = main.c eval.c

INCLUDES = /evalexpr.h

OBJECTS = $(SOURCES:.c=.o) 

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ -I $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) $< -o $@ -I $(INCLUDES)

clean:
	/bin/rm -f $(OBJECTS) 

fclean: clean
	/bin/rm -f $(NAME)

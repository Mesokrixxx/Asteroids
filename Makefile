NAME = Asteroids

CC = clang-18
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lSDL2 -lGLEW -lGL

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJ) $(NAME)

run: all
	./$(NAME)

ren: clean run

re: clean all

.PHONY: all clean run ren re

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/gui.c
OBJ = $(SRC:.c=.o)
LIB = libgui.a

all: $(LIB) demo

$(LIB): $(OBJ)
	$(AR) rcs $(LIB) $(OBJ)

demo: examples/demo.c $(LIB)
	$(CC) $(CFLAGS) -o demo examples/demo.c -L. -lgui -lX11

clean:
	rm -f $(OBJ) $(LIB) demo


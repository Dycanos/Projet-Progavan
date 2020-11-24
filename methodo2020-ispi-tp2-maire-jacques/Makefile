CFLAGS = -O3 `sdl2-config --cflags` -Iinclude -g -Wall
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = $(shell find -type f -name "*.h")
SRC = $(shell find -type f \( -iname "*.c" ! -iname "tests.c" \))
OBJ = $(SRC:.c=.o)

PROG = spacebattle

.o: .c $(INC)
	gcc $(CFLAGS) -c $<

$(PROG): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OBJ) $(PROG)

re:
	make clean
	make

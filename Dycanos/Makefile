CFLAGS = -O3 `sdl2-config --cflags` -Iinclude -g -Wall
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = $(shell find -type f -name "*.h")
SRC = $(shell find -type f \( -iname "*.c" ! -iname "tests.c" \))
OBJ = $(SRC:.c=.o)

PROG = minijeu

.o: .c $(INC)
	gcc $(CFLAGS) -c $<

spacebattle: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

clean:
	rm -f *~ $(OBJ) $(PROG)
	rm -rf latex html

re:
	make clean
	make

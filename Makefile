.PHONY: all  clean
BB=gcc -Wall -Werror

all: bin/game

bin/game: repository  build/main.o build/menu.o build/game.o 
	$(BB) build/main.o build/menu.o build/game.o -o bin/game -lncurses
build/main.o: src/main.c
	$(BB) -c -o build/main.o src/main.c -lncurses
build/menu.o: src/menu.c
	$(BB) -c -o build/menu.o src/menu.c -lncurses
build/game.o: src/game.c
	$(BB) -c -o build/game.o src/game.c -lncurses

repository:
	mkdir -p bin
	mkdir -p build
clean:
	rm -rf bin/game
	rm -rf build/*.o
	rm -R bin
	rm -R build

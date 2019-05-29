.PHONY: all  clean test
BB=g++ -Wall -Werror
SFMLFIX = -lsfml-graphics -lsfml-window -lsfml-system

all: bin/game

bin/game: repository  build/src/main.o build/src/menu.o build/src/game.o 
	$(BB) build/src/main.o build/src/menu.o build/src/game.o -o bin/game -lncurses $(SFMLFIX)
build/src/main.o: src/main.c
	$(BB) -c -o build/src/main.o src/main.c -lncurses $(SFMLFIX)
build/src/menu.o: src/menu.c
	$(BB) -c -o build/src/menu.o src/menu.c -lncurses $(SFMLFIX)
build/src/game.o: src/game.c
	$(BB) -c -o build/src/game.o src/game.c -lncurses $(SFMLFIX)

repository:
	mkdir -p bin
	mkdir -p build
	mkdir -p build/src
clean:
	rm -rf bin/game
	rm -rf -R build

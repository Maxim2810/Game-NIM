.PHONY: all  clean
BB=gcc -Wall -Werror


repository:
	mkdir -p bin
	mkdir -p build
clean:
	rm -rf bin/game
	rm -rf build/*.o
	rm -R bin
	rm -R build

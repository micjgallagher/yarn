args = -g
main:
	gcc main.c yarn.c $(args) -o main

clean:
	rm -f main 
run: main
	./main
test:
	make clean --no-print-directory
	make run --no-print-directory

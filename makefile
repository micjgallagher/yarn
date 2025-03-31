main:
	gcc main.c yarn.c -o main

clean:
	rm -f main 
run: main
	./main
test:
	make clean --no-print-directory
	make run --no-print-directory

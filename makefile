main:
	gcc main.c yarn.c -o main

clean:
	-rm main 2> /dev/null
run: clean main
	./main


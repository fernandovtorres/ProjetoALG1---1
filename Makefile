all: graph dp brute vertice deque main maindp
	gcc -lm ./src/graph.o ./src/brute.o ./src/deque.o ./src/vertice.o ./src/main.o -o ./src/main -Wall  -std=c99 
	gcc ./src/dp.o ./src/maindp.o -o ./src/maindp -Wall -std=c99
	rm ./src/*.o

graph:
	gcc -c ./libs/impl/graph.c -o ./src/graph.o

brute:
	gcc -c ./libs/impl/brute.c -o ./src/brute.o

vertice:
	gcc -c ./libs/impl/vertice.c -o ./src/vertice.o

deque:
	gcc -c ./libs/impl/deque.c -o ./src/deque.o

dp:
	gcc -c ./libs/impl/dp.c -o ./src/dp.o

main:
	gcc -c ./src/main.c -o ./src/main.o

maindp:
	gcc -c ./src/maindp.c -o ./src/maindp.o

run:
	./src/main

rundp:
	./src/maindp

clean:
	rm ./src/main
	rm ./src/maindp

remake: clean all

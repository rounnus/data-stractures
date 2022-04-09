INCLUDE = -I ./include
OBJS = ./build/linkedlist.o

all: ${OBJS}
	mkdir ./bin/
	gcc ./src/question1/main.c ${OBJS} -o ./bin/question1 
	gcc ./src/question2/main.c ${OBJS} -o ./bin/question2

 
./build/linkedlist.o: ./src/linkedlist.c
	mkdir ./build/
	gcc ./src/linkedlist.c -c -o ./build/linkedlist.o

clean:
	rm -rf ./build/*



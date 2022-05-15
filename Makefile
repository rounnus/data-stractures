INCLUDE = -I ./include
OBJS = ./build/linkedlist.o

all: ${OBJS}
	mkdir -p ./bin/
	g++ ./src/question1/main.cpp ${OBJS} -o ./bin/question1 
	g++ ./src/question2/main.cpp ${OBJS} -o ./bin/question2

 
./build/linkedlist.o: ./src/linkedlist.cpp
	mkdir -p ./build/
	g++ ./src/linkedlist.cpp ${INCLUDE} -c -o ./build/linkedlist.o

clean:
	rm -rf ./build/*




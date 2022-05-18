INCLUDE = -I ./include

all: ${OBJS}
	mkdir -p ./bin/
	g++ ${INCLUDE} ./src/question1/main.cpp -o ./bin/question1 
	g++ ${INCLUDE} ./src/question2/main.cpp -o ./bin/question2


clean:
	rm -rf ./build/*




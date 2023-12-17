FLAGS= -std=c++20 -Wall -Iinclude -c

all:  main

main: parser.o recommender.o main.o 
	g++ parser.o recommender.o main.o -o main

main.o: src/main.cpp include/parser.h
	g++ $(FLAGS) src/main.cpp

parser.o: src/parser.cpp include/parser.h
	g++ $(FLAGS) src/parser.cpp

recommender.o: src/recommender.cpp include/recommender.h
	g++ $(FLAGS) src/recommender.cpp

clean: 
	rm -f *.o *.h.gch main



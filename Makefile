FLAGS= -std=c++11 -Wall -Iinclude -c

all:  main

main: parser.o main.o 
	g++ -std=c++11 -Wall parser.o main.o -o main

main.o: src/main.cpp include/parser.h
	g++ $(FLAGS) src/main.cpp

parser.o: src/parser.cpp include/parser.h
	g++ $(FLAGS) src/parser.cpp

recommender.o: src/parser.cpp include/parser.h
	g++ $(FLAGS) src/parser.cpp

# If src/parser.cpp doesn't exist, create a dummy one
src/parser.cpp: include/parser.h
	echo "This is a placeholder for src/parser.cpp" > src/parser.cpp

clean: 
	rm -f *.o *.h.gch main



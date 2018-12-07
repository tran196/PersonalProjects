###
### 
###  Tuan Tran
###  Project 1

output: main.o ant.o board.o
	g++ -std=c++11 main.o ant.o board.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ant.o: ant.cpp
	g++ -std=c++11 -c ant.cpp

board.o: board.cpp
	g++ -std=c++11 -c board.cpp

clean:
	rm *.o output

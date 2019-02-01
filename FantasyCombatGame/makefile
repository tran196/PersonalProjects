###
### 
###  Tuan Tran
###  Project 4

# output: main.o character.o barbarian.o medusa.o harryPotter.o blueMen.o vampire.o queue.o
# 	g++ -std=c++11 main.o character.o barbarian.o medusa.o harryPotter.o blueMen.o vampire.o queue.o -o output

output: main.o character.o barbarian.o medusa.o harryPotter.o blueMen.o vampire.o Node.o DoubleLinkedList.o
	g++ -std=c++11 main.o character.o barbarian.o medusa.o harryPotter.o blueMen.o vampire.o Node.o DoubleLinkedList.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

character.o: character.cpp
	g++ -std=c++11 -c character.cpp

barbarian.o: barbarian.cpp
	g++ -std=c++11 -c barbarian.cpp

medusa.o: medusa.cpp
	g++ -std=c++11 -c medusa.cpp

harryPotter.o: harryPotter.cpp
	g++ -std=c++11 -c harryPotter.cpp

blueMen.o: blueMen.cpp
	g++ -std=c++11 -c blueMen.cpp

vampire.o: vampire.cpp
	g++ -std=c++11 -c vampire.cpp

# queue.o: Queue.cpp
# 	g++ -std=c++11 -c Queue.cpp

Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -std=c++11 -c DoubleLinkedList.cpp

clean:
	rm *.o output

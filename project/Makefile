CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: main

# сборка программы
main: main.o RedBlackTree.o Array.o CommandProcessor.o SinglyLinkedList.o DoublyLinkedList.o Stack.o Queue.o
	$(CXX) $(CXXFLAGS) -o main main.o RedBlackTree.o Array.o CommandProcessor.o SinglyLinkedList.o DoublyLinkedList.o Stack.o Queue.o

# компиляция main
main.o: main.cpp RedBlackTree.h Array.h CommandProcessor.h SinglyLinkedList.h DoublyLinkedList.h Stack.h Queue.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# компиляция дерева
RedBlackTree.o: RedBlackTree.cpp RedBlackTree.h
	$(CXX) $(CXXFLAGS) -c RedBlackTree.cpp

# компиляция массива
Array.o: Array.cpp Array.h
	$(CXX) $(CXXFLAGS) -c Array.cpp

# компиляция процессора команд
CommandProcessor.o: CommandProcessor.cpp CommandProcessor.h
	$(CXX) $(CXXFLAGS) -c CommandProcessor.cpp

# компиляция односвязного списка
SinglyLinkedList.o: SinglyLinkedList.cpp SinglyLinkedList.h
	$(CXX) $(CXXFLAGS) -c SinglyLinkedList.cpp

# компиляция двусвязного списка
DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	$(CXX) $(CXXFLAGS) -c DoublyLinkedList.cpp

# компиляция стека
Stack.o: Stack.cpp Stack.h
	$(CXX) $(CXXFLAGS) -c Stack.cpp

# компиляция очереди
Queue.o: Queue.cpp Queue.h
	$(CXX) $(CXXFLAGS) -c Queue.cpp

# очистка
clean:
	rm -f *.o main

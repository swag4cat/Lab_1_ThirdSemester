#include "Array.h"
#include "SinglyLinkedList.h"
#include "CommandProcessor.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "RedBlackTree.h"

#include <sstream>
#include <iostream>
#include <fstream>

// ----- Вспомогательные функции для Array -----
void loadArrayFromFile(const std::string& filename, Array& arr) { // загрузка массива из файла
    std::ifstream fin(filename);
    if (!fin.is_open()) return;
    int value;
    while (fin >> value) {
        arr.push(value);
    }
    fin.close();
}

void saveArrayToFile(const std::string& filename, Array& arr) { // сохранение массива в файл
    std::ofstream fout(filename);
    if (!fout.is_open()) return;
    for (size_t i = 0; i < arr.size(); i++) {
        fout << arr.get(i) << " ";
    }
    fout.close();
}

// ----- Вспомогательные функции для Tree -----
void loadTreeFromFile(const std::string& filename, RedBlackTree& tree) { // загрузка дерева из файла
    std::ifstream fin(filename);
    if (!fin.is_open()) return;
    int value;
    while (fin >> value) {
        tree.insert(value);
    }
    fin.close();
}

void saveTreeToFile(const std::string& filename, RedBlackTree& tree) { // сохранение дерева в файл
    std::ofstream fout(filename);
    if (!fout.is_open()) return;

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    tree.print();
    std::cout.rdbuf(oldCout);

    fout << buffer.str();
    fout.close();
}

// ----- Вспомогательные функции для SinglyLinkedList -----
void loadListFromFile(const std::string& filename, SinglyLinkedList& list) { // загрузка односвязного списка
    std::ifstream fin(filename);
    if (!fin.is_open()) return;

    int value;
    while (fin >> value) {
        list.pushBack(value); // читаем и добавляем в хвост
    }
    fin.close();
}

void saveListToFile(const std::string& filename, SinglyLinkedList& list) { // сохранение односвязного списка
    std::ofstream fout(filename);
    if (!fout.is_open()) return;

    for (int val : list.toVector()) {
        fout << val << " ";
    }
    fout.close();
}

// ----- Вспомогательные функции для DoublyLinkedList -----
void loadDoublyListFromFile(const std::string& filename, DoublyLinkedList& list) { // загрузка двусвязного списка
    std::ifstream fin(filename);
    if (!fin.is_open()) return;

    int value;
    while (fin >> value) {
        list.pushBack(value);
    }
    fin.close();
}

void saveDoublyListToFile(const std::string& filename, DoublyLinkedList& list) { // сохранение двусвязного списка
    std::ofstream fout(filename);
    if (!fout.is_open()) return;

    for (int val : list.toVector()) {
        fout << val << " ";
    }
    fout.close();
}

// ----- Вспомогательные функции для Stack -----
void loadStackFromFile(const std::string& filename, Stack& stack) { // загрузка стека из файла
    std::ifstream fin(filename);
    if (!fin.is_open()) return;

    int value;
    while (fin >> value) {
        stack.push(value);
    }
    fin.close();
}

void saveStackToFile(const std::string& filename, Stack& stack) { // сохранение стека в файл
    std::ofstream fout(filename);
    if (!fout.is_open()) return;

    for (int val : stack.toVector()) {
        fout << val << " ";
    }
    fout.close();
}

// ----- Вспомогательные функции для Queue -----
void loadQueueFromFile(const std::string& filename, Queue& queue) { // загрузка очереди из файла
    std::ifstream fin(filename);
    if (!fin.is_open()) return;

    int value;
    while (fin >> value) {
        queue.push(value);
    }
    fin.close();
}

void saveQueueToFile(const std::string& filename, Queue& queue) { // сохранение очереди в файл
    std::ofstream fout(filename);
    if (!fout.is_open()) return;

    for (int val : queue.toVector()) {
        fout << val << " ";
    }
    fout.close();
}


// ----- Обработка команд -----
void CommandProcessor::execute(const std::string& query, const std::string& filename) {
    std::istringstream iss(query);
    std::string command, name;
    iss >> command >> name;

    // ---- TREE ----
    if (command == "TINSERT") { // вставка в дерево
        int value; iss >> value;
        RedBlackTree tree;
        loadTreeFromFile(filename, tree);
        tree.insert(value);
        saveTreeToFile(filename, tree);
        std::cout << "-> вставлен " << value << std::endl;
    }
    else if (command == "TDEL") { // удаление из дерева
        int value; iss >> value;
        RedBlackTree tree;
        loadTreeFromFile(filename, tree);

        // проверяем существование элемента перед удалением
        if (tree.contains(value)) {
            tree.remove(value);
            saveTreeToFile(filename, tree);
            std::cout << "-> удалён " << value << std::endl;
        } else {
            std::cout << "Ошибка: элемент " << value << " не найден" << std::endl;
        }
    }
    else if (command == "TGET") { // поиск в дереве
        int value; iss >> value;
        RedBlackTree tree;
        loadTreeFromFile(filename, tree);
        std::cout << "-> " << (tree.contains(value) ? "TRUE" : "FALSE") << std::endl;
    }
    else if (command == "PRINT") { // печать дерева
        RedBlackTree tree;
        loadTreeFromFile(filename, tree);
        std::cout << "-> ";
        tree.print();
    }

    // ---- ARRAY ----
    else if (command == "MPUSH") { // добавление в массив
        int value; iss >> value;
        Array arr;
        loadArrayFromFile(filename, arr);
        arr.push(value);
        saveArrayToFile(filename, arr);
        std::cout << "-> добавлен " << value << std::endl;
    }
    else if (command == "MDEL") { // удаление из массива
        int index; iss >> index;
        Array arr;
        loadArrayFromFile(filename, arr);

        // Проверяем валидность индекса перед удалением
        if (index >= 0 && index < (int)arr.size()) {
            arr.delAt(index);
            saveArrayToFile(filename, arr);
            std::cout << "-> удалён элемент по индексу " << index << std::endl;
        } else {
            std::cout << "Ошибка: индекс " << index << " вне диапазона" << std::endl;
        }
    }
    else if (command == "MGET") { // получение из массива
        int index; iss >> index;
        Array arr;
        loadArrayFromFile(filename, arr);
        std::cout << "-> " << arr.get(index) << std::endl;
    }
    else if (command == "PRINTM") { // печать массива
        Array arr;
        loadArrayFromFile(filename, arr);
        std::cout << "-> ";
        arr.print();
    }

    else if (command == "MINDEX") { // вставка по индексу
        int index, value; iss >> index >> value;
        Array arr;
        loadArrayFromFile(filename, arr);

        // проверяем валидность индекса перед вставкой
        if (index >= 0 && index <= (int)arr.size()) {
            arr.insertAt(index, value);
            saveArrayToFile(filename, arr);
            std::cout << "-> вставлен " << value << " по индексу " << index << std::endl;
        } else {
            std::cout << "Ошибка: индекс " << index << " вне диапазона" << std::endl;
        }
    }
    else if (command == "MSET") { // замена по индексу
        int index, value; iss >> index >> value;
        Array arr;
        loadArrayFromFile(filename, arr);
        arr.set(index, value);
        saveArrayToFile(filename, arr);
        std::cout << "-> заменён элемент по индексу " << index << " на " << value << std::endl;
    }


    // ---- SINGLY LINKED LIST ----
    else if (command == "FPUSH") { // добавление в односвязный список
        int value; iss >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        list.pushBack(value);
        saveListToFile(filename, list);
        std::cout << "-> добавлен " << value << std::endl;
    }
    else if (command == "FDEL") { // удаление из односвязного списка
        int value; iss >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        bool ok = list.delByValue(value);
        saveListToFile(filename, list);
        if (ok)
            std::cout << "-> удалён " << value << std::endl;
        else
            std::cout << "-> элемент " << value << " не найден" << std::endl;
    }
    else if (command == "FGET") { // получение из односвязного списка
        int index; iss >> index;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        std::cout << "-> " << list.get(index) << std::endl;
    }
    else if (command == "PRINTF") { // печать односвязного списка
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        std::cout << "-> ";
        list.print();
    }

    else if (command == "FPUSHFRONT") { // добавление в начало односвязного списка
        int value; iss >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        list.pushFront(value);
        saveListToFile(filename, list);
        std::cout << "-> добавлен " << value << " в голову" << std::endl;
    }
    else if (command == "FINSERTBEFORE") { // вставка перед элементом
        int target, value; iss >> target >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        list.insertBefore(target, value);
        saveListToFile(filename, list);
        std::cout << "-> вставлен " << value << " перед " << target << std::endl;
    }
    else if (command == "FINSERTAFTER") { // вставка после элемента
        int target, value; iss >> target >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        list.insertAfter(target, value);
        saveListToFile(filename, list);
        std::cout << "-> вставлен " << value << " после " << target << std::endl;
    }

    else if (command == "FDELFRONT") { // удаление первого элемента
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        bool ok = list.delFront();
        saveListToFile(filename, list);
        if (ok) std::cout << "-> удалён первый элемент" << std::endl;
        else std::cout << "Ошибка: список пуст" << std::endl;
    }
    else if (command == "FDELBACK") { // удаление последнего элемента
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        bool ok = list.delBack();
        saveListToFile(filename, list);
        if (ok) std::cout << "-> удалён последний элемент" << std::endl;
        else std::cout << "Ошибка: список пуст" << std::endl;
    }


    else if (command == "FCONTAINS") { // проверка наличия элемента
        int value; iss >> value;
        SinglyLinkedList list;
        loadListFromFile(filename, list);
        bool found = list.contains(value);
        std::cout << "-> " << (found ? "найден " : "не найден ") << value << std::endl;
    }

    // ---- DOUBLY LINKED LIST ----
    else if (command == "LPUSH") { // добавление в двусвязный список
        int value; iss >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        list.pushBack(value);
        saveDoublyListToFile(filename, list);
        std::cout << "-> добавлен " << value << std::endl;
    }
    else if (command == "LDEL") { // удаление из двусвязного списка
        int value; iss >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        bool ok = list.delByValue(value);
        saveDoublyListToFile(filename, list);
        if (ok)
            std::cout << "-> удалён " << value << std::endl;
        else
            std::cout << "-> элемент " << value << " не найден" << std::endl;
    }
    else if (command == "LGET") { // получение из двусвязного списка
        int index; iss >> index;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        std::cout << "-> " << list.get(index) << std::endl;
    }
    else if (command == "PRINTL") { // печать двусвязного списка
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        std::cout << "-> ";
        list.print();
    }

    else if (command == "LPUSHFRONT") { // добавление в начало двусвязного списка
        int value; iss >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        list.pushFront(value);
        saveDoublyListToFile(filename, list);
        std::cout << "-> добавлен " << value << " в голову" << std::endl;
    }
    else if (command == "LINSERTBEFORE") { // вставка перед элементом
        int target, value; iss >> target >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        list.insertBefore(target, value);
        saveDoublyListToFile(filename, list);
        std::cout << "-> вставлен " << value << " перед " << target << std::endl;
    }
    else if (command == "LINSERTAFTER") { // вставка после элемента
        int target, value; iss >> target >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        list.insertAfter(target, value);
        saveDoublyListToFile(filename, list);
        std::cout << "-> вставлен " << value << " после " << target << std::endl;
    }

    else if (command == "LCONTAINS") { // проверка наличия элемента
        int value; iss >> value;
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        bool found = list.contains(value);
        std::cout << "-> " << (found ? "найден " : "не найден ") << value << std::endl;
    }

    else if (command == "LDELFRONT") { // удаление первого элемента
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        bool ok = list.delFront();
        saveDoublyListToFile(filename, list);
        if (ok) std::cout << "-> удалён первый элемент" << std::endl;
        else std::cout << "Ошибка: список пуст" << std::endl;
    }
    else if (command == "LDELBACK") { // удаление последнего элемента
        DoublyLinkedList list;
        loadDoublyListFromFile(filename, list);
        bool ok = list.delBack();
        saveDoublyListToFile(filename, list);
        if (ok) std::cout << "-> удалён последний элемент" << std::endl;
        else std::cout << "Ошибка: список пуст" << std::endl;
    }

    // ---- STACK ----
    else if (command == "SPUSH") { // добавление в стек
        int value; iss >> value;
        Stack stack;
        loadStackFromFile(filename, stack);
        stack.push(value);
        saveStackToFile(filename, stack);
        std::cout << "-> добавлен " << value << std::endl;
    }
    else if (command == "SPOP") { // удаление из стека
        Stack stack;
        loadStackFromFile(filename, stack);
        if (!stack.empty()) {
            int value = stack.top();
            stack.pop();
            saveStackToFile(filename, stack);
            std::cout << "-> удалён верхний элемент " << value << std::endl;
        } else {
            std::cout << "Ошибка: стек пуст" << std::endl;
        }
    }
    else if (command == "PRINTS") { // печать стека
        Stack stack;
        loadStackFromFile(filename, stack);
        std::cout << "-> ";
        stack.print();
    }

    // ---- QUEUE ----
    else if (command == "QPUSH") { // добавление в очередь
        int value; iss >> value;
        Queue queue;
        loadQueueFromFile(filename, queue);
        queue.push(value);
        saveQueueToFile(filename, queue);
        std::cout << "-> добавлен " << value << std::endl;
    }
    else if (command == "QPOP") { // удаление из очереди
        Queue queue;
        loadQueueFromFile(filename, queue);
        if (!queue.empty()) {
            int value = queue.front();
            queue.pop();
            saveQueueToFile(filename, queue);
            std::cout << "-> удалён первый элемент " << value << std::endl;
        } else {
            std::cout << "Ошибка: очередь пуста" << std::endl;
        }
    }
    else if (command == "PRINTQ") { // печать очереди
        Queue queue;
        loadQueueFromFile(filename, queue);
        std::cout << "-> ";
        queue.print();
    }


    else {
        std::cerr << "Неизвестная команда: " << command << std::endl;
    }
}

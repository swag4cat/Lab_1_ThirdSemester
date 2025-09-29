#pragma once
#include <iostream>
#include <vector>

struct LNode {                              // узел двусвязного списка
    int data;
    LNode* next;
    LNode* prev;
    LNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {                    // двусвязный список
private:
    LNode* head;                            // указатель на голову
    LNode* tail;                            // указатель на хвост
public:
    DoublyLinkedList();                     // конструктор
    ~DoublyLinkedList();                    // деструктор

     bool contains(int value) const;        // проверить наличие

    void pushFront(int value);               // в голову
    void pushBack(int value);                // в хвост
    void insertBefore(int target, int value);// до элемента
    void insertAfter(int target, int value); // после элемента
    bool delByValue(int value);              // удалить по значению
    int get(int index);                      // получить по индексу
    void print() const;                      // вывод
    std::vector<int> toVector() const;       // вернуть все элементы
};

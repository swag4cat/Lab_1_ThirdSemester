#pragma once
#include <iostream>
#include <vector>

struct FNode {                                          // узел односвязного списка
    int data;
    FNode* next;
    FNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {                                // односвязный список
private:
    FNode* head;                                        // указатель на голову
public:
    SinglyLinkedList();                                 // конструктор
    ~SinglyLinkedList();                                // деструктор

     bool contains(int value) const;                    // проверить наличие

    void pushFront(int value);                          // в голову
    void pushBack(int value);                           // в хвост
    void insertBefore(int target, int value);           // до элемента
    void insertAfter(int target, int value);            // после элемента
    bool delByValue(int value);                         // удалить по значению
    int get(int index);                                 // получить по индексу
    void print() const;                                 // вывод
    std::vector<int> toVector() const;                  // вернуть все элементы
};

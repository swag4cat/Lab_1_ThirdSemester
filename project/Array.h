#pragma once
#include <vector>
#include <iostream>


class Array {                              // класс динамического массива
private:
    std::vector<int> data;                 // внутреннее хранилище данных
public:
    void push(int value);                  // добавить в конец
    void insertAt(int index, int value);   // вставка по индексу
    void delAt(int index);                 // удалить по индексу
    int get(int index);                    // получить элемент
    void set(int index, int value);        // заменить по индексу
    size_t size() const;                   // длина массива
    void print() const;                    // вывод
};

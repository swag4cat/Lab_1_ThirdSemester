#pragma once
#include <iostream>
#include <vector>

class Stack {                                   // класс стека
private:
    std::vector<int> data;                      // внутреннее хранилище
public:
    void push(int value);                       // добавить элемент
    void pop();                                 // удалить вершину
    int top() const;                            // посмотреть вершину
    bool empty() const;                         // проверка пустоты
    void print() const;                         // вывод содержимого
    std::vector<int> toVector() const;          // конвертация в вектор
};

#include "Stack.h"

void Stack::push(int value) { // добавить в стек
    data.push_back(value);
}

void Stack::pop() { // удалить с вершины
    if (!data.empty()) {
        data.pop_back();
    } else {
        std::cerr << "Ошибка: стек пуст\n";
    }
}

int Stack::top() const { // получить вершину
    if (!data.empty()) {
        return data.back();
    }
    std::cerr << "Ошибка: стек пуст\n";
    return -1;
}

bool Stack::empty() const { // проверка на пустоту
    return data.empty();
}

void Stack::print() const { // вывод стека
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

std::vector<int> Stack::toVector() const { // преобразовать в вектор
    return data;
}

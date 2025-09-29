#include "Queue.h"

void Queue::push(int value) { // добавить в очередь
    data.push_back(value);
}

void Queue::pop() { // удалить из начала
    if (!data.empty()) {
        data.erase(data.begin()); // удаляем первый элемент
    } else {
        std::cerr << "Ошибка: очередь пуста\n";
    }
}

int Queue::front() const { // получить первый элемент
    if (!data.empty()) {
        return data.front();
    }
    std::cerr << "Ошибка: очередь пуста\n";
    return -1;
}

bool Queue::empty() const { // проверка на пустоту
    return data.empty();
}

void Queue::print() const { // вывод очереди
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

std::vector<int> Queue::toVector() const { // преобразовать в вектор
    return data;
}

#include "Array.h"

// добавить в конец
void Array::push(int value) {
    data.push_back(value);
}

// вставка по индексу
void Array::insertAt(int index, int value) {
    if (index < 0 || index > (int)data.size()) {
        std::cerr << "Ошибка: индекс вне диапазона\n";
        return;
    }
    data.insert(data.begin() + index, value);
}

// удалить по индексу
void Array::delAt(int index) {
    if (index < 0 || index >= (int)data.size()) {
        std::cerr << "Ошибка: индекс вне диапазона\n";
        return;
    }
    data.erase(data.begin() + index);
}

// получить элемент
int Array::get(int index) {
    if (index < 0 || index >= (int)data.size()) {
        std::cerr << "Ошибка: индекс вне диапазона\n";
        return -1;
    }
    return data[index];
}

// заменить по индексу
void Array::set(int index, int value) {
    if (index < 0 || index >= (int)data.size()) {
        std::cerr << "Ошибка: индекс вне диапазона\n";
        return;
    }
    data[index] = value;
}

// длина массива
size_t Array::size() const {
    return data.size();
}

// вывод
void Array::print() const {
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

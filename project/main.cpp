#include "CommandProcessor.h"

#include <iostream>
#include <string>

std::string getArgValue(int argc, char* argv[], const std::string& key) { // получить значение аргумента
    for (int i = 1; i < argc - 1; i++) {
        if (argv[i] == key) return argv[i + 1];
    }
    return "";
}

int main(int argc, char* argv[]) { // главная функция

    if (argc > 1) {
        std::string arg1 = argv[1];

        if (arg1 == "--help") { // справка по программе
            std::cout << "Использование: ./main --file <файл> --query \"<КОМАНДА>\"\n";
            std::cout << "Флаги справки:\n";
            std::cout << "  -a : команды для массива\n";
            std::cout << "  -f : команды для односвязного списка\n";
            std::cout << "  -l : команды для двусвязного списка\n";
            std::cout << "  -s : команды для стека\n";
            std::cout << "  -q : команды для очереди\n";
            std::cout << "  -t : команды для дерева\n";
            return 0;
        }
        else if (arg1 == "-a") { // справка по массиву
            std::cout << "Команды для массива:\n"
            << "  MPUSH <x>           - добавить в конец\n"
            << "  MINDEX <i> <x>      - вставить по индексу\n"
            << "  MGET <i>            - получить элемент\n"
            << "  MSET <i> <x>        - заменить элемент\n"
            << "  MDEL <i>            - удалить элемент\n"
            << "  PRINTM              - вывести массив\n";
            return 0;
        }
        else if (arg1 == "-f") { // справка по односвязному списку
            std::cout << "Команды для односвязного списка:\n"
            << "  FPUSHFRONT <x>      - добавить в голову\n"
            << "  FPUSH <x>           - добавить в хвост\n"
            << "  FINSERTBEFORE <t> <x> - вставить перед t\n"
            << "  FINSERTAFTER <t> <x>  - вставить после t\n"
            << "  FDEL <x>            - удалить по значению\n"
            << "  FDELFRONT <x>       - удалить первый элемент\n"
            << "  FDELBACK <x>        - удалить последний элемент\n"
            << "  FCONTAINS <x>       - поиск элемента\n"
            << "  FGET <i>            - получить по индексу\n"
            << "  PRINTF              - вывести список\n";
            return 0;
        }
        else if (arg1 == "-l") { // справка по двусвязному списку
            std::cout << "Команды для двусвязного списка:\n"
            << "  LPUSHFRONT <x>      - добавить в голову\n"
            << "  LPUSH <x>           - добавить в хвост\n"
            << "  LINSERTBEFORE <t> <x> - вставить перед t\n"
            << "  LINSERTAFTER <t> <x>  - вставить после t\n"
            << "  LDEL <x>            - удалить по значению\n"
            << "  LDELFRONT <x>       - удалить первый элемент\n"
            << "  LDELBACK <x>        - удалить последний элемент\n"
            << "  LCONTAINS <x>       - поиск элемента\n"
            << "  LGET <i>            - получить по индексу\n"
            << "  PRINTL              - вывести список\n";
            return 0;
        }
        else if (arg1 == "-s") { // справка по стеку
            std::cout << "Команды для стека:\n"
            << "  SPUSH <x>           - push\n"
            << "  SPOP                - pop\n"
            << "  PRINTS              - вывести стек\n";
            return 0;
        }
        else if (arg1 == "-q") { // справка по очереди
            std::cout << "Команды для очереди:\n"
            << "  QPUSH <x>           - enqueue\n"
            << "  QPOP                - dequeue\n"
            << "  PRINTQ              - вывести очередь\n";
            return 0;
        }
        else if (arg1 == "-t") { // справка по дереву
            std::cout << "Команды для дерева (красно-чёрного):\n"
            << "  TINSERT <x>         - вставить\n"
            << "  TDEL <x>            - удалить\n"
            << "  TGET <x>            - поиск\n"
            << "  PRINT               - вывести дерево (in-order)\n";
            return 0;
        }
    }



    if (argc < 5) {
        std::cerr << "Использование: ./main --file file.data --query \"COMMAND\"\n";
        return 1;
    }

    std::string filename = getArgValue(argc, argv, "--file");
    std::string query = getArgValue(argc, argv, "--query");

    CommandProcessor processor;
    processor.execute(query, filename);

    return 0;
}

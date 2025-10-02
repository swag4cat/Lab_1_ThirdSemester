package main

import "fmt"

func printGeneralHelp() {
	fmt.Println("Общая справка:")
	fmt.Println("Использование: ./project --file <файл> --query \"<команда>\"")
	fmt.Println("Доступные структуры данных:")
	fmt.Println("  -a   Справка по массиву")
	fmt.Println("  -f   Справка по односвязному списку")
	fmt.Println("  -l   Справка по двусвязному списку")
	fmt.Println("  -s   Справка по стеку")
	fmt.Println("  -q   Справка по очереди")
	fmt.Println("Пример: ./project --file array.txt --query \"MPUSH myarray 10\"")
}

func printArrayHelp() {
	fmt.Println("Справка: Массив (Array)")
	fmt.Println("  MPUSH <name> <value>      - добавить элемент в конец")
	fmt.Println("  MINDEX <name> <i> <value> - вставить элемент по индексу")
	fmt.Println("  MGET <name> <i>           - получить элемент по индексу")
	fmt.Println("  MSET <name> <i> <value>   - заменить элемент по индексу")
	fmt.Println("  MDEL <name> <i>           - удалить элемент по индексу")
	fmt.Println("  PRINTM <name>             - вывести массив")
}

func printSinglyListHelp() {
	fmt.Println("Справка: Односвязный список (Singly Linked List)")
	fmt.Println("  FPUSH <name> <value>          - добавить в хвост")
	fmt.Println("  FPUSHFRONT <name> <value>     - добавить в голову")
	fmt.Println("  FINSERTBEFORE <name> <x> <v>  - вставить v перед x")
	fmt.Println("  FINSERTAFTER <name> <x> <v>   - вставить v после x")
	fmt.Println("  FDEL <name> <value>           - удалить элемент по значению")
	fmt.Println("  FDELFRONT <name> <value>      - удалить первый элемент")
	fmt.Println("  FDELBACK <name> <value>       - удалить последний элемент")
	fmt.Println("  FGET <name> <i>               - получить элемент по индексу")
	fmt.Println("  FCONTAINS <name> <value>      - проверить наличие элемента")
	fmt.Println("  PRINTF <name>                 - вывести список")
}

func printDoublyListHelp() {
	fmt.Println("Справка: Двусвязный список (Doubly Linked List)")
	fmt.Println("  LPUSH <name> <value>          - добавить в хвост")
	fmt.Println("  LPUSHFRONT <name> <value>     - добавить в голову")
	fmt.Println("  LINSERTBEFORE <name> <x> <v>  - вставить v перед x")
	fmt.Println("  LINSERTAFTER <name> <x> <v>   - вставить v после x")
	fmt.Println("  LDEL <name> <value>           - удалить элемент по значению")
	fmt.Println("  LDELFRONT <name> <value>      - удалить первый элемент")
	fmt.Println("  LDELBACK <name> <value>       - удалить последний элемент")
	fmt.Println("  LGET <name> <i>               - получить элемент по индексу")
	fmt.Println("  LCONTAINS <name> <value>      - проверить наличие элемента")
	fmt.Println("  PRINTL <name>                 - вывести список")
}

func printStackHelp() {
	fmt.Println("Справка: Стек (Stack)")
	fmt.Println("  SPUSH <name> <value> - добавить элемент в стек")
	fmt.Println("  SPOP <name>          - удалить верхний элемент")
	fmt.Println("  PRINTS <name>        - вывести содержимое стека")
}

func printQueueHelp() {
	fmt.Println("Справка: Очередь (Queue)")
	fmt.Println("  QPUSH <name> <value> - добавить элемент в очередь")
	fmt.Println("  QPOP <name>          - удалить первый элемент")
	fmt.Println("  PRINTQ <name>        - вывести содержимое очереди")
}

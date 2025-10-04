#!/bin/bash

echo "Запуск комплексного тестирования проекта..."
echo "================================================"

# Сборка проекта
echo "Собираю проект..."
go build -o project main.go commands.go io.go slist.go dlist.go stack.go queue.go help.go
if [ $? -ne 0 ]; then
  echo "Ошибка сборки!"
  exit 1
fi
echo "Сборка завершена успешно"

# Создаем тестовые файлы (обнуляем)
: > test_array.txt
: > test_slist.txt
: > test_dlist.txt
: > test_stack.txt
: > test_queue.txt

echo ""
echo "1. ТЕСТИРОВАНИЕ МАССИВА"
echo "======================="
./project --file test_array.txt --query "MPUSH arr 10"
./project --file test_array.txt --query "MPUSH arr 20"
./project --file test_array.txt --query "MPUSH arr 30"
./project --file test_array.txt --query "PRINTM arr"
./project --file test_array.txt --query "MINDEX arr 0 5"
./project --file test_array.txt --query "MINDEX arr 2 15"
./project --file test_array.txt --query "MINDEX arr 10 100"  # ошибка
./project --file test_array.txt --query "MGET arr 2"
./project --file test_array.txt --query "MGET arr 999"       # ошибка
./project --file test_array.txt --query "MSET arr 2 99"
./project --file test_array.txt --query "MDEL arr 0"
./project --file test_array.txt --query "MDEL arr 999"       # ошибка
./project --file test_array.txt --query "PRINTM arr"

echo ""
echo "2. ТЕСТИРОВАНИЕ ОДНОСВЯЗНОГО СПИСКА"
echo "==================================="
./project --file test_slist.txt --query "FPUSH slist 10"
./project --file test_slist.txt --query "FPUSH slist 30"
./project --file test_slist.txt --query "FPUSHFRONT slist 5"
./project --file test_slist.txt --query "PRINTF slist"
./project --file test_slist.txt --query "FINSERTBEFORE slist 30 20"
./project --file test_slist.txt --query "FINSERTAFTER slist 10 15"
./project --file test_slist.txt --query "PRINTF slist"
./project --file test_slist.txt --query "FGET slist 2"
./project --file test_slist.txt --query "FGET slist 999"     # ошибка
./project --file test_slist.txt --query "FCONTAINS slist 20"
./project --file test_slist.txt --query "FDEL slist 20"
./project --file test_slist.txt --query "FDEL slist 999"     # ошибка
./project --file test_slist.txt --query "FDELFRONT slist 15"
./project --file test_slist.txt --query "FDELBACK slist 10"
./project --file test_slist.txt --query "PRINTF slist"

echo ""
echo "3. ТЕСТИРОВАНИЕ ДВУСВЯЗНОГО СПИСКА"
echo "=================================="
./project --file test_dlist.txt --query "LPUSH dlist 100"
./project --file test_dlist.txt --query "LPUSH dlist 300"
./project --file test_dlist.txt --query "LPUSHFRONT dlist 50"
./project --file test_dlist.txt --query "PRINTL dlist"
./project --file test_dlist.txt --query "LINSERTBEFORE dlist 300 200"
./project --file test_dlist.txt --query "LINSERTAFTER dlist 100 75"
./project --file test_dlist.txt --query "PRINTL dlist"
./project --file test_dlist.txt --query "LGET dlist 0"
./project --file test_dlist.txt --query "LCONTAINS dlist 75"
./project --file test_dlist.txt --query "LDEL dlist 50"
./project --file test_slist.txt --query "LDELFRONT dlist 200"
./project --file test_slist.txt --query "LDELBACK dlist 100"
./project --file test_dlist.txt --query "PRINTL dlist"

echo ""
echo "4. ТЕСТИРОВАНИЕ СТЕКА"
echo "====================="
./project --file test_stack.txt --query "SPUSH stack 1"
./project --file test_stack.txt --query "SPUSH stack 2"
./project --file test_stack.txt --query "SPUSH stack 3"
./project --file test_stack.txt --query "PRINTS stack"
./project --file test_stack.txt --query "SPOP stack"
./project --file test_stack.txt --query "PRINTS stack"
./project --file test_stack.txt --query "SPOP stack"
./project --file test_stack.txt --query "SPOP stack"
./project --file test_stack.txt --query "SPOP stack"         # ошибка

echo ""
echo "5. ТЕСТИРОВАНИЕ ОЧЕРЕДИ"
echo "======================="
./project --file test_queue.txt --query "QPUSH queue 10"
./project --file test_queue.txt --query "QPUSH queue 20"
./project --file test_queue.txt --query "QPUSH queue 30"
./project --file test_queue.txt --query "PRINTQ queue"
./project --file test_queue.txt --query "QPOP queue"
./project --file test_queue.txt --query "PRINTQ queue"
./project --file test_queue.txt --query "QPOP queue"
./project --file test_queue.txt --query "QPOP queue"
./project --file test_queue.txt --query "QPOP queue"         # ошибка

echo ""
echo "6. ТЕСТ НЕИЗВЕСТНОЙ КОМАНДЫ"
echo "==========================="
./project --file test_array.txt --query "FOO bar xyz"        # ошибка

echo ""
echo "================================================"
echo "Тестирование завершено!"
echo "Файлы с данными: test_*.txt"

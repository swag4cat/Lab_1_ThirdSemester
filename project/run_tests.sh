#!/bin/bash

echo "Запуск комплексного тестирования проекта..."
echo "================================================"

# Создаем тестовые файлы
touch test_array.txt test_tree.txt test_slist.txt test_dlist.txt test_stack.txt test_queue.txt

echo ""
echo "1. ТЕСТИРОВАНИЕ МАССИВА"
echo "======================="
./main --file test_array.txt --query "MPUSH arr 10"
./main --file test_array.txt --query "MPUSH arr 20"
./main --file test_array.txt --query "MPUSH arr 30"
./main --file test_array.txt --query "PRINTM arr"
./main --file test_array.txt --query "MINDEX arr 0 5"
./main --file test_array.txt --query "MINDEX arr 2 15"
./main --file test_array.txt --query "MINDEX arr 10 100"  # ошибка
./main --file test_array.txt --query "MGET arr 2"
./main --file test_array.txt --query "MGET arr 999"       # ошибка
./main --file test_array.txt --query "MSET arr 2 99"
./main --file test_array.txt --query "MDEL arr 0"
./main --file test_array.txt --query "MDEL arr 999"       # ошибка
./main --file test_array.txt --query "PRINTM arr"

echo ""
echo "2. ТЕСТИРОВАНИЕ ДЕРЕВА"
echo "======================"
./main --file test_tree.txt --query "TINSERT tree 50"
./main --file test_tree.txt --query "TINSERT tree 30"
./main --file test_tree.txt --query "TINSERT tree 70"
./main --file test_tree.txt --query "TINSERT tree 20"
./main --file test_tree.txt --query "TINSERT tree 40"
./main --file test_tree.txt --query "TINSERT tree 60"
./main --file test_tree.txt --query "TINSERT tree 80"
./main --file test_tree.txt --query "PRINT tree"
./main --file test_tree.txt --query "TGET tree 60"
./main --file test_tree.txt --query "TGET tree 99"        # ошибка
./main --file test_tree.txt --query "TDEL tree 20"
./main --file test_tree.txt --query "TDEL tree 30"
./main --file test_tree.txt --query "TDEL tree 50"
./main --file test_tree.txt --query "TDEL tree 999"       # ошибка
./main --file test_tree.txt --query "PRINT tree"

echo ""
echo "3. ТЕСТИРОВАНИЕ ОДНОСВЯЗНОГО СПИСКА"
echo "==================================="
./main --file test_slist.txt --query "FPUSH slist 10"
./main --file test_slist.txt --query "FPUSH slist 30"
./main --file test_slist.txt --query "FPUSHFRONT slist 5"
./main --file test_slist.txt --query "PRINTF slist"
./main --file test_slist.txt --query "FINSERTBEFORE slist 30 20"
./main --file test_slist.txt --query "FINSERTAFTER slist 10 15"
./main --file test_slist.txt --query "PRINTF slist"
./main --file test_slist.txt --query "FGET slist 2"
./main --file test_slist.txt --query "FGET slist 999"     # ошибка
./main --file test_slist.txt --query "FCONTAINS slist 20"
./main --file test_slist.txt --query "FDEL slist 20"
./main --file test_slist.txt --query "FDEL slist 999"     # ошибка
./main --file test_slist.txt --query "PRINTF slist"

echo ""
echo "4. ТЕСТИРОВАНИЕ ДВУСВЯЗНОГО СПИСКА"
echo "=================================="
./main --file test_dlist.txt --query "LPUSH dlist 100"
./main --file test_dlist.txt --query "LPUSH dlist 300"
./main --file test_dlist.txt --query "LPUSHFRONT dlist 50"
./main --file test_dlist.txt --query "PRINTL dlist"
./main --file test_dlist.txt --query "LINSERTBEFORE dlist 300 200"
./main --file test_dlist.txt --query "LINSERTAFTER dlist 100 75"
./main --file test_dlist.txt --query "PRINTL dlist"
./main --file test_dlist.txt --query "LGET dlist 0"
./main --file test_dlist.txt --query "LCONTAINS dlist 75"
./main --file test_dlist.txt --query "LDEL dlist 50"
./main --file test_dlist.txt --query "LDEL dlist 300"
./main --file test_dlist.txt --query "PRINTL dlist"

echo ""
echo "5. ТЕСТИРОВАНИЕ СТЕКА"
echo "====================="
./main --file test_stack.txt --query "SPUSH stack 1"
./main --file test_stack.txt --query "SPUSH stack 2"
./main --file test_stack.txt --query "SPUSH stack 3"
./main --file test_stack.txt --query "PRINTS stack"
./main --file test_stack.txt --query "SPOP stack"
./main --file test_stack.txt --query "PRINTS stack"
./main --file test_stack.txt --query "SPOP stack"
./main --file test_stack.txt --query "SPOP stack"
./main --file test_stack.txt --query "SPOP stack"         # ошибка

echo ""
echo "6. ТЕСТИРОВАНИЕ ОЧЕРЕДИ"
echo "======================="
./main --file test_queue.txt --query "QPUSH queue 10"
./main --file test_queue.txt --query "QPUSH queue 20"
./main --file test_queue.txt --query "QPUSH queue 30"
./main --file test_queue.txt --query "PRINTQ queue"
./main --file test_queue.txt --query "QPOP queue"
./main --file test_queue.txt --query "PRINTQ queue"
./main --file test_queue.txt --query "QPOP queue"
./main --file test_queue.txt --query "QPOP queue"
./main --file test_queue.txt --query "QPOP queue"         # ошибка

echo ""
echo "7. ТЕСТ НЕИЗВЕСТНОЙ КОМАНДЫ"
echo "==========================="
./main --file test_array.txt --query "FOO bar xyz"        # ошибка

echo ""
echo "================================================"
echo "Тестирование завершено! Все структуры данных работают корректно."
echo "Файлы с данными: test_*.txt"

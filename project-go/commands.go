package main

import (
	"fmt"
	"strconv"
	"strings"
)

// Array структура (динамический массив)
type Array struct {
	data []int
}

func (a *Array) Push(value int) {
	a.data = append(a.data, value)
}

func (a *Array) Insert(index int, value int) bool {
	if index < 0 || index > len(a.data) {
		fmt.Println("Ошибка: индекс вне диапазона")
		return false
	}
	a.data = append(a.data[:index], append([]int{value}, a.data[index:]...)...)
	return true
}

func (a *Array) Get(index int) int {
	if index < 0 || index >= len(a.data) {
		fmt.Println("Ошибка: индекс вне диапазона")
		return -1
	}
	return a.data[index]
}

func (a *Array) Set(index int, value int) bool {
	if index < 0 || index >= len(a.data) {
		fmt.Println("Ошибка: индекс вне диапазона")
		return false
	}
	a.data[index] = value
	return true
}

func (a *Array) Delete(index int) bool {
	if index < 0 || index >= len(a.data) {
		fmt.Println("Ошибка: индекс вне диапазона")
		return false
	}
	a.data = append(a.data[:index], a.data[index+1:]...)
	return true
}

func (a *Array) Print() {
	for _, v := range a.data {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

// Обработка команды для массива
func handleArrayCommand(array *Array, parts []string) {
	if len(parts) < 2 {
		fmt.Println("Ошибка: пустая команда для массива")
		return
	}

	switch parts[0] {
		case "MPUSH":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			array.Push(val)
			fmt.Println("-> добавлен", val)

		case "MINDEX":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите индекс и значение")
				return
			}
			idx, err1 := strconv.Atoi(parts[2])
			val, err2 := strconv.Atoi(parts[3])
			if err1 != nil || err2 != nil {
				fmt.Println("Ошибка: неверные параметры")
				return
			}
			if array.Insert(idx, val) {
				fmt.Println("-> вставлен", val, "по индексу", idx)
			}

		case "MGET":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите индекс")
				return
			}
			idx, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверный индекс")
				return
			}
			val := array.Get(idx)
			fmt.Println("->", val)

		case "MSET":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите индекс и новое значение")
				return
			}
			idx, err1 := strconv.Atoi(parts[2])
			val, err2 := strconv.Atoi(parts[3])
			if err1 != nil || err2 != nil {
				fmt.Println("Ошибка: неверные параметры")
				return
			}
			if array.Set(idx, val) {
				fmt.Println("-> элемент по индексу", idx, "заменён на", val)
			}

		case "MDEL":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите индекс")
				return
			}
			idx, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверный индекс")
				return
			}
			if array.Delete(idx) {
				fmt.Println("-> удалён элемент по индексу", idx)
			} else {
				fmt.Println("Удаление не выполнено (индекс вне диапазона)")
			}

		case "PRINTM":
			fmt.Print("-> ")
			array.Print()

		default:
			fmt.Println("Неизвестная команда:", parts[0])
	}
}

// Обработка команд для односвязного списка
func handleSListCommand(list *SinglyLinkedList, parts []string) {
	if len(parts) < 2 {
		fmt.Println("Ошибка: пустая команда для списка")
		return
	}

	switch parts[0] {
		case "FPUSH":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			list.PushBack(val)
			fmt.Println("-> добавлен", val)

		case "FPUSHFRONT":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			list.PushFront(val)
			fmt.Println("-> добавлен", val, "в голову")

		case "FINSERTBEFORE":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите target и value")
				return
			}
			target, _ := strconv.Atoi(parts[2])
			val, _ := strconv.Atoi(parts[3])
			if list.InsertBefore(target, val) {
				fmt.Println("-> вставлен", val, "перед", target)
			} else {
				fmt.Println("Элемент", target, "не найден")
			}

		case "FINSERTAFTER":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите target и value")
				return
			}
			target, _ := strconv.Atoi(parts[2])
			val, _ := strconv.Atoi(parts[3])
			if list.InsertAfter(target, val) {
				fmt.Println("-> вставлен", val, "после", target)
			} else {
				fmt.Println("Элемент", target, "не найден")
			}

		case "FDEL":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, _ := strconv.Atoi(parts[2])
			if list.Delete(val) {
				fmt.Println("-> удалён", val)
			} else {
				fmt.Println("Элемент", val, "не найден")
			}

		case "FGET":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите индекс")
				return
			}
			idx, _ := strconv.Atoi(parts[2])
			val := list.Get(idx)
			fmt.Println("->", val)

		case "FCONTAINS":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, _ := strconv.Atoi(parts[2])
			if list.Contains(val) {
				fmt.Println("-> найден", val)
			} else {
				fmt.Println("-> не найден", val)
			}

		case "FDELFRONT":
			if list.DelFront() {
				fmt.Println("-> удалён первый элемент")
			} else {
				fmt.Println("Ошибка: список пуст")
			}

		case "FDELBACK":
			if list.DelBack() {
				fmt.Println("-> удалён последний элемент")
			} else {
				fmt.Println("Ошибка: список пуст")
			}

		case "PRINTF":
			fmt.Print("-> ")
			list.Print()

		default:
			fmt.Println("Неизвестная команда:", parts[0])
	}
}

// Обработка команд двусвязного списка
func handleDListCommand(dlist *DoublyLinkedList, parts []string) {
	if len(parts) < 2 {
		fmt.Println("Ошибка: пустая команда для списка")
		return
	}

	switch parts[0] {
		case "LPUSH":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			dlist.PushBack(val)
			fmt.Println("-> добавлен", val)

		case "LPUSHFRONT":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			dlist.PushFront(val)
			fmt.Println("-> добавлен", val, "в голову")

		case "LINSERTBEFORE":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите target и значение")
				return
			}
			target, err1 := strconv.Atoi(parts[2])
			val, err2 := strconv.Atoi(parts[3])
			if err1 != nil || err2 != nil {
				fmt.Println("Ошибка: неверные параметры")
				return
			}
			if dlist.InsertBefore(target, val) {
				fmt.Println("-> вставлен", val, "перед", target)
			} else {
				fmt.Println("Элемент", target, "не найден")
			}

		case "LINSERTAFTER":
			if len(parts) < 4 {
				fmt.Println("Ошибка: укажите target и значение")
				return
			}
			target, err1 := strconv.Atoi(parts[2])
			val, err2 := strconv.Atoi(parts[3])
			if err1 != nil || err2 != nil {
				fmt.Println("Ошибка: неверные параметры")
				return
			}
			if dlist.InsertAfter(target, val) {
				fmt.Println("-> вставлен", val, "после", target)
			} else {
				fmt.Println("Элемент", target, "не найден")
			}

		case "LDEL":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			if dlist.Delete(val) {
				fmt.Println("-> удалён", val)
			} else {
				fmt.Println("Элемент", val, "не найден")
			}

		case "LGET":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите индекс")
				return
			}
			idx, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверный индекс")
				return
			}
			val := dlist.Get(idx)
			fmt.Println("->", val)

		case "LCONTAINS":
			if len(parts) < 3 {
				fmt.Println("Ошибка: укажите значение")
				return
			}
			val, err := strconv.Atoi(parts[2])
			if err != nil {
				fmt.Println("Ошибка: неверное значение")
				return
			}
			if dlist.Contains(val) {
				fmt.Println("-> найден", val)
			} else {
				fmt.Println("->", val, "не найден")
			}

		case "LDELFRONT":
			if dlist.DelFront() {
				fmt.Println("-> удалён первый элемент")
			} else {
				fmt.Println("Ошибка: список пуст")
			}

		case "LDELBACK":
			if dlist.DelBack() {
				fmt.Println("-> удалён последний элемент")
			} else {
				fmt.Println("Ошибка: список пуст")
			}

		case "PRINTL":
			fmt.Print("-> ")
			dlist.Print()

		default:
			fmt.Println("Неизвестная команда:", parts[0])
	}
}

// Разбор строки команды
func executeCommand(query string) {
	parts := strings.Fields(query)
	if len(parts) == 0 {
		fmt.Println("Ошибка: пустая команда")
		return
	}

	switch {
		case strings.HasPrefix(parts[0], "M") || parts[0] == "PRINTM":
			handleArrayCommand(&globalArray, parts)
		case strings.HasPrefix(parts[0], "F") || parts[0] == "PRINTF":
			handleSListCommand(&globalSList, parts)
		case strings.HasPrefix(parts[0], "L") || parts[0] == "PRINTL":
			handleDListCommand(&globalDList, parts)
		case strings.HasPrefix(parts[0], "S") || parts[0] == "PRINTS":
			handleStackCommand(&globalStack, parts)
		case strings.HasPrefix(parts[0], "Q") || parts[0] == "PRINTQ":
			handleQueueCommand(&globalQueue, parts)
		default:
			fmt.Println("Неизвестная команда:", parts[0])
	}
}

// Глобальная структура (для простоты)
var globalArray Array
var globalSList SinglyLinkedList
var globalDList DoublyLinkedList
var globalStack Stack
var globalQueue Queue

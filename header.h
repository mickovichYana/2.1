#ifndef HEADER_H
#define HEADER_H
#include <deque>
#include <list>
#include <iostream>

template <typename Container>
//Заполняет контейнер целыми числами
void Input(Container& N, int n);

template <typename Container>
// Выводит содержимое контейнера в прямом порядке
void Print(const Container& N);
// Вывод в обратном порядке
template <typename Container>
void PrintReverse(const Container& N);
//Вставляет последние 5 элементов дека в обратном порядке 
// перед 5-м с конца элементом списка.
void Insert(std::deque<int>& D, std::list<int>& L);

#endif
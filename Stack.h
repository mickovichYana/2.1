#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack {
private:
  struct Node {
    int d;
    Node* next;
    Node(int val);  
  };
  Node* p1; 
  int cnt;

public:
  Stack(); //Конструктор
  ~Stack(); //Деструктор для освобождения памяти
  void Add(int x); //Добавление элемента в стек
  void Pop(); //Извлечение из стека
  void Show() const; //Вывод элементов  
};

#endif 
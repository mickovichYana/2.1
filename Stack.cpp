#include "Stack.h"
#include <iostream>

Stack::Node::Node(int val) : d(val), next(nullptr) {}

Stack::Stack() : p1(nullptr), cnt(0) {}

// FIX_ME: Деструктор для освобождения памяти
Stack::~Stack() {
  while (p1 != nullptr) {
    Node* temp = p1;
    p1 = p1->next;
    delete temp;
  }
}

void Stack::Add(int x) {
  Node* new_node = new Node(x);
  new_node->next = p1;
  p1 = new_node;
  cnt++;
}

// FIX_ME: Метод переименован в Pop
void Stack::Pop() {
  // FIX_ME: Добавлена проверка на пустой стек
  if (p1 == nullptr) {
    std::cout << "Ошибка: стек пуст!" << std::endl;
    return;
  }
  Node* temp = p1;
  int deleted_value = p1->d;

  // FIX_ME: Исправлена логика удаления - убрана лишняя проверка на nullptr
  /* if (p1->next == nullptr) {
       p1 = nullptr;
   }
   else {
       p1 = p1->next;
   }*/
  p1 = p1->next;  
  // FIX_ME: Исправлен вывод - теперь выводится значение D и адрес P2
  /* cout << "Адрес новой вершины p1 после извлечения 1 элемента: " 
  << p1 << endl;*/
  std::cout << "Значение извлеченного элемента D: " << deleted_value 
  << std::endl;
  std::cout << "Адрес новой вершины P2: " << p1 << std::endl;

  // FIX_ME: Добавлена проверка на случай, если стек стал пустым
  if (p1 == nullptr) {
    std::cout << "Стек стал пустым, P2 = nullptr" << std::endl;
  }
  else {
    std::cout << "Значение новой вершины: " << p1->d << std::endl;
  }

  delete temp;  
  cnt--;
}

void Stack::Show() const {
  // FIX_ME: Добавлена проверка на пустой стек
  if (p1 == nullptr) {
    std::cout << "Стек пуст" << std::endl;
    return;
  }
  Node* temp = p1;
  while (temp != nullptr) {
    std::cout << temp->d << std::endl;
    temp = temp->next;
  }
}
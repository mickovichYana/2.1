#include "queue.h"

// FIX_ME: старый код создавал узел частично и только потом присваивал данные
// старый код:
/*
void Add(int data, PNode& Head, PNode& Tail) {
    PNode Temp;
    if (Head == NULL)
    {
        Head = new Node;
        Tail = Head;
        Head->next = NULL;
    }
    else
    {
        Temp = new Node;
        Tail->next = Temp;
        Tail = Temp;
        Tail->next = NULL;
    }
    Tail->data = data;
}
*/

void Add(int data, PNode& head, PNode& tail) {
  PNode temp = new Node;
  temp->data = data;
  temp->next = nullptr;
  if (head == nullptr) {
    head = temp;
    tail = temp;
  }
  else {
    tail->next = temp;
    tail = temp;
  }
}

// FIX_ME: старый код не проверял очередь на пустоту и избыточно проходил по списку дважды
// старый код:
/*
void Show_Initial(PNode head, PNode tail) {
    PNode temp = head;
    cout << endl << "Исходный адрес первого элемента: " << head << " " <<
    head->data; cout << endl << "Исходная очередь: "; while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    PNode last = head;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    cout << endl << "Исходный адрес последнего элемента: " << last << " " <<
    last->data << endl;
}
*/

void Show_Initial(PNode head, PNode tail) {
  if (head == nullptr) {
    std::cout << "Очередь пуста" << std::endl;
    return;
  }
  std::cout << std::endl
  << "Исходный адрес первого элемента: " << head << " " << head->data;
  std::cout << std::endl << "Исходная очередь: ";
  PNode temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl
  << "Исходный адрес последнего элемента: " << tail << " "
  << tail->data << std::endl;
}

// FIX_ME: старый код выводил лишнюю информацию (адрес next) и не обновлял Tail
// старый код:
/*
void Remove_Elements(int n, PNode& head, PNode& tail) {
    PNode temp;
    for (int i = 0; i < m; i++)
    {
        temp = Head;
        cout << temp->data << " " << temp->next << " ";
        Head = Head->next;
        delete temp;
        cout << endl;
    }
    cout << endl;
}
*/

void Remove_Elements(int n, PNode& head, PNode& tail) {
  std::cout << "Извлеченные элементы: ";
  for (int i = 0; i < n; i++) {
    if (head == nullptr) break;
    PNode temp = head;
    std::cout << temp->data << " ";
    head = head->next;
    delete temp;
    if (head == nullptr) {
      tail = nullptr;
    }
  }
  std::cout << std::endl;
}

// FIX_ME: старый код неправильно выводил nullptr (выводил адрес указателя, а не само слово nullptr)
// FIX_ME: старый код имел закомментированное удаление в цикле просмотра
// старый код:
/*
void Show_Final(PNode head, PNode tail) {
    PNode temp = nullptr;
    PNode temp2 = head;
    if (head == nullptr)
    {
        cout << "Очередь после удаления элементов оказалась пустой" << endl;
        int* ptr = nullptr;
        cout << "Начало очереди: " << ptr  << endl;
        cout << "Конец очереди: " << ptr << endl;
    }
    else
    {
        cout << "Новое начало очереди: " << temp2 << " " << temp2->data << endl;
        cout << "Оставшиеся элементы очереди: ";
        while (head != nullptr)
        {
            temp = head;
            cout << temp->data << " ";
            head = head->next;
            //delete temp;
        }
        cout << endl << "Новый конец очереди: " << temp << " " << temp->data <<
    endl;
    }
}
*/

void Show_Final(PNode head, PNode tail) {
  if (head == nullptr) {
    std::cout << "Очередь после удаления элементов оказалась пустой"
    << std::endl;
    std::cout << "Начало очереди: nullptr" << std::endl;
    std::cout << "Конец очереди: nullptr" << std::endl;
  }
  else {
    std::cout << "Новое начало очереди: " << head << " " << head->data
    << std::endl;
    std::cout << "Оставшиеся элементы очереди: ";
    PNode temp = head;
    while (temp != nullptr) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl
    << "Новый конец очереди: " << tail << " " << tail->data
    << std::endl;
  }
}
/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вставить значение M после каждого второго элемента списка, и вывести ссылку на последний
элемент полученного списка P2.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/



/*
//FIX_ME: В условии задачи нужно вставлять после каждого ВТОРОГО элемента, а в коде реализовано после каждого ТРЕТЬЕГО
//FIX_ME: В условии задачи нужно вывести ссылку на последний элемент (P2), но в коде выводится адрес и значение
//FIX_ME: В функции addafter используется магическое число 4 вместо логики для второго элемента
//FIX_ME: Отсутствует проверка на пустой список в некоторых функциях
//FIX_ME: В main некорректное описание задачи для пользователя
*/

#include <windows.h>
#include <iostream>

class Node {
public:
  int x;
  Node* next;
};
typedef Node* PNode;

void Add(int data, PNode& head, PNode& last_node) {
    PNode temp;
    if (head == nullptr) {
        head = new Node;
        last_node = head;
        head->next = nullptr;
    }
    else {
        temp = new Node;
        last_node->next = temp;
        last_node = temp;
        last_node->next = nullptr;
    }
    last_node->x = data;
}

void Show(PNode& head) {
    //FIX_ME: Добавлена проверка на пустой список
    if (head == nullptr) {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    PNode mynode = head;
    std::cout << "Все числа из списка: ";

    while (mynode != nullptr) {
        std::cout << mynode->x << " ";
        mynode = mynode->next;
    }
}

//FIX_ME: Переделана для вставки после каждого ВТОРОГО элемента
void Add_After(int data, PNode& head) {
    //FIX_ME: Проверка на минимальную длину списка
    if (head == nullptr || head->next == nullptr) {
        std::cout << "Список слишком короткий для вставки после второго элемента!"
            << std::endl;
        return;
    }

    PNode temp = head;
    PNode my_node;
    int count = 0;  //FIX_ME: Счетчик элементов

    while (temp != nullptr) {
        count++;
        //FIX_ME: Вставка после каждого ВТОРОГО элемента
        if (count == 2) {
            my_node = new Node;
            my_node->x = data;
            my_node->next = temp->next;
            temp->next = my_node;
            temp = my_node->next;  // Переходим к следующему после вставленного
            count = 0;  //FIX_ME: Сбрасываем счетчик
        }
        else {
            temp = temp->next;
        }
    }
}

void Show_After(PNode& head) {
    //FIX_ME: Добавлена проверка на пустой список
    if (head == nullptr) {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    PNode mynode = head;
    std::cout << std::endl;
    std::cout << "Все числа из измененного списка: ";
    while (mynode != nullptr) {
        std::cout << mynode->x << " ";
        mynode = mynode->next;
    }
    std::cout << std::endl;
}

PNode Show_Last(PNode& head) {
    //FIX_ME: Добавлена проверка на пустой список
    if (head == nullptr) {
        std::cout << "Список пуст!" << std::endl;
        return nullptr;
    }

    PNode mynode2 = head;
    while (mynode2 != nullptr && mynode2->next != nullptr) {
        mynode2 = mynode2->next;
    }
    return mynode2;
}

PNode Find(PNode head, int data) {
    PNode q = head;
    while (q && q->x != data) q = q->next;
    return q;
}

void Delete_Node(PNode& head, PNode old_node) {
    //FIX_ME: Добавлена проверка на nullptr
    if (head == nullptr || old_node == nullptr) {
        std::cout << "Некорректные параметры для удаления!" << std::endl;
        return;
    }

    PNode q = head;
    if (head == old_node) {
        head = old_node->next;
    }
    else {
        while (q->next != old_node) q = q->next;
        q->next = old_node->next;
    }
    delete old_node;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PNode h1 = nullptr;
    PNode last_node = nullptr;

    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами задача: " << std::endl;
    std::cout << "Дан односвязный линейный список" << std::endl;
    //FIX_ME: Исправлено описание задачи в соответствии с условием
    //std::cout << "Необходимо вставить значение M после каждого третьего элемента списка," << std::endl;
    std::cout << "Необходимо вставить значение M после каждого второго элемента списка,"
        << std::endl;
    std::cout << "и вывести ссылку на последний элемент полученного списка P2."
        << std::endl;
    std::cout << "-------------------------------------------------------------------"
        << std::endl;
    std::cout << "Вам необходимо ввести два значения: " << std::endl;
    std::cout << "1. n - количество элементов в списке" << std::endl;
    std::cout << "2. m - число, которое мы будем вставлять. " << std::endl;
    std::cout << "Затем через пробел ввести элементы списка, количество которых будет совпадать с тем, что вы ввели ранее,"
        << std::endl;
    std::cout << "После мы выведем полученный результат на экран и ссылку на последний элемент. "
        << std::endl;
    std::cout << "--------------------------------------------------------"
        << std::endl;
    std::cout << "Введите число - количество элементов в списке: ";
    int n, x, m;
    std::cin >> n;

    //FIX_ME: Добавлена проверка на положительное количество элементов
    if (n <= 0) {
        std::cout << "Количество элементов должно быть положительным!" << std::endl;
        return 1;
    }

    std::cout << "Введите " << n << " элементов списка: ";
    for (int i = 1; i <= n; i++) {
        std::cin >> x;
        Add(x, h1, last_node);
    }
    std::cout << std::endl;
    std::cout << "Введите значение m для вставки после каждого второго элемента: ";
    std::cin >> m;
    std::cout << std::endl;

    Show(h1);
    std::cout << std::endl;

    Add_After(m, h1);
    Show_After(h1);
    std::cout << std::endl;

    PNode last = Show_Last(h1);
    //FIX_ME: Изменен вывод в соответствии с заданием (нужна только ссылка P2)
    if (last != nullptr) {
        std::cout << "Ссылка на последний элемент: " << last << std::endl;
        std::cout << "Значение последнего элемента: " << last->x << std::endl;
    }

    int choice;
    std::cout << std::endl << "Хотите удалить какой-нибудь элемент?" << std::endl;
    std::cout << "Если да, то напишите 1" << std::endl;
    std::cout << "Если нет, то напишите 2" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    std::cout << std::endl;

    switch (choice) {
    case 1: {
        std::cout << "Введите число - количество элементов которое вы хотите удалить: ";
        int num;
        std::cin >> num;

        //FIX_ME: Добавлена проверка на количество удаляемых элементов
        if (num <= 0) {
            std::cout << "Количество удаляемых элементов должно быть положительным!"
                << std::endl;
            break;
        }

        for (int i = 0; i < num; i++) {
            std::cout << "Введите значение элемента, который вы хотите удалить: ";
            int x;
            std::cin >> x;
            PNode p = Find(h1, x);

            //FIX_ME: Проверка на существование элемента
            if (p == nullptr) {
                std::cout << "Элемент со значением " << x << " не найден!" << std::endl;
            }
            else {
                std::cout << std::endl;
                std::cout << "Удаление...." << std::endl;
                Delete_Node(h1, p);
            }
        }
        Show(h1);
        break;
    }

    case 2: {
        std::cout << "Спасибо за терпение!!!" << std::endl;
        std::cout << "До свидания!!!" << std::endl;
        break;
    }

    default: {
        std::cout << "Введено неверное число";
        break;
    }
    }

    //FIX_ME: Добавлено освобождение памяти
    while (h1 != nullptr) {
        PNode temp = h1;
        h1 = h1->next;
        delete temp;
    }

    return 0;
}
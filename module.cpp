#include "header.h"
#include <ctime>
#include <fstream>

//FIX_ME: неправильное использование конструктора контейнера
//вставка через N.insert(N.end(), x)
template <typename Container>
void Input(Container& N, int n){
  int m, x;
  std::cout << "Выберете способ заполнения контейнера: " << std::endl;
  std::cout << "1)Ввод с клавиатуры." << std::endl;
  std::cout << "2)Ввод с помощью рандомайзера." << std::endl;
  std::cout << "3)Ввод данных из текстового файла." << std::endl;
  std::cin >> m;
  if (n < 5) {
    std::cout << "Ошибка. Недопустимый размер." << std::endl;
    return;
  }
  switch (m){
    case 1:{
      //FIX_ME:использую временный массив и конструктор с итераторами
      int* temp = new int[n];
      for (int i = 0; i < n; i++){
        std::cout << "Введите " << i + 1 << " элемент: ";
        std::cin >> temp[i];
      }
      Container tempContainer(temp, temp + n);
      N = tempContainer;
      delete[] temp;
      break;
    }
    case 2: {
      std::srand(std::time(0));
      //FIX_ME: использую временный массив и конструктор с итераторами
      int* temp = new int[n];
      for (int i = 0; i < n; i++) {
        temp[i] = std::rand() % 101 - 50;
      }
      Container tempContainer(temp, temp + n);
      N = tempContainer;
      delete[] temp;
      break;
    }
    case 3:{
      std::ifstream file("a.txt", std::ios::in);
      if (!file) {
        std::cout << "Ошибка. Файл не был открыт.";
        return;
      }
      //FIX_ME: использую временный массив и конструктор с итераторами
      int* temp = new int[n];
      for (int i = 0; i < n; i++) {
        file >> x;
        temp[i] = x;
      }
      Container tempContainer(temp, temp + n);
      N = tempContainer;
      delete[] temp;
      file.close();
      break;
    }
    default:{
      std::cout << "Ошибка ввода." << std::endl;
      break;
    }
  }
}

//FIX_ME: для вывода в обратном порядке нужно использовать обратные итераторы
//обычный вывод через begin/end
template <typename Container>
void Print(const Container& N){
  for (auto it = N.begin(); it != N.end(); ++it) {
    std::cout << *it << " ";
    std::cout << std::endl;
  }
}

//FIX_ME: добавлена функция для вывода в обратном порядке
template <typename Container>
void PrintReverse(const Container& N){
  for (auto it = N.rbegin(); it != N.rend(); ++it) {
    std::cout << *it << " ";
    std::cout << std::endl;
  }
}

//FIX_ME: нужно использовать один вызов insert
//цикл с множественными вызовами insert
void Insert(std::deque<int>& D, std::list<int>& L){
  std::list<int>::iterator it = L.end();
  for (int i = 0; i < 5; ++i)
    --it;
  std::deque<int> temp;
  for (int i = D.size() - 1; i >= static_cast<int>(D.size()) - 5; --i)
    temp.push_back(D[i]);
    L.insert(it, temp.begin(), temp.end());
}

template void Input<std::deque<int>>(std::deque<int>&, int);
template void Input<std::list<int>>(std::list<int>&, int);
template void Print<std::deque<int>>(const std::deque<int>&);
template void Print<std::list<int>>(const std::list<int>&);
template void PrintReverse<std::deque<int>>(const std::deque<int>&);
template void PrintReverse<std::list<int>>(const std::list<int>&);
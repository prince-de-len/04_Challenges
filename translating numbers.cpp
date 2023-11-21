/*************************************
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 1
* Название: Частота повторений
* Ссылка: https://onlinegdb.com/Y1yA-VsYOW
************************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toRoman(int num) {
  const vector<pair<int, string>> roman = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
    {1, "I"}};
  
  string result = "";
  for (const auto &r : roman) {
    while (num >= r.first) {
      result += r.second;
      num -= r.first;
    }
  }
  return result;
}

int main() {
  int number;
  cout << "Введите число (1-3999): ";
  cin >> number;
  
  if (number < 1 || number > 3999) {
    cout << "Число вне допустимого диапазона";
    return 1;
  }
  
  cout << "Римское представление: " << toRoman(number) << endl;
  
  return 0;
}

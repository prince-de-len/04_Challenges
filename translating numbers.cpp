/*************************************
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 1.1
* Название: Частота повторений
* Ссылка: https://onlinegdb.com/PWnGeDAPN
************************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toRoman(int num) {
  const vector<pair<int, string>> roman = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
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

int toArabian(string num) {
  const vector<pair<int, string>> roman = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
    {1, "I"}};

  int result = 0;
  for (const auto &r : roman) {
    while (num.substr(0, r.second.length()) == r.second) {
      result += r.first;
      num = num.substr(r.second.length());
      if (num.empty()) {
        break;
      }
    }
  }
  
  return result;
  
}

int main() {
  int number;
  
  cout << "Введите арабское число (1-3999): ";
  cin >> number;

  if (number < 1 || number > 3999) {
    cout << "Число вне допустимого диапазона" << endl;
    return 1;
  }

  cout << "Римское представление: " << toRoman(number) << endl;
  
  string number_r;
  
  cout << "Введите римское число (I-MMMCMXCIX): ";
  cin >> number_r;

  if (number_r.substr(0, 4) == "MMMM") {
   cout << "Число вне допустимого диапазона" << endl;
    return 1;
  }

  cout << "Арабское представление: " << toArabian(number_r) << endl;

  return 0;
  
}

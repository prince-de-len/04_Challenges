/*************************************
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 1
* Название: Частота повторений
* Ссылка: https://onlinegdb.com/dt7E0KLm_
************************************/

#include <stdio.h>
#include <iostream>
#include "string"
#include <fstream>

using namespace std;

int main() {
  int counter_letter, counter_combo;
  char letter, ch_prev, ch_curr;
  string combo, combo_;
  string path = "/Users/princedelen/Documents/Xcode/Xstudy/data.txt";
  
  counter_letter = 0;
  counter_combo = 0;
  combo_ = "";
  
  printf("Введите букву: ");
  cin >> letter;
  printf("Введите двухбуквенное сочетание: ");
  cin >> combo;
  
  ifstream file(path);
  
  if (!file.is_open()) {
      cout << "Не удалось открыть файл";
      return 1;
  }
  
  file.get(ch_prev);
  
  if (ch_prev == letter) {
    ++counter_letter;
  }
  
  while (file.get(ch_curr)) {
    
    if (ch_curr == letter) {
      ++counter_letter;
    }
    
    combo_ += ch_prev;
    combo_ += ch_curr;

    if (combo == combo_) {
      ++counter_combo;
    }
    
    ch_prev = ch_curr;
    combo_ = "";
  }
  
  file.close();
  
  printf("Количество однобуквенных повторений: %d\nКоличество двухбуквенных повторений: %d\n",
  counter_letter - 1, counter_combo - 1);
  
  return 0;
  
}



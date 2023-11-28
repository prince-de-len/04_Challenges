#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<string> months = {"Январь", "Февраль", "Март", "Апрель", "Май",
  "Июнь", "Июль", "Август", "Сентябрь",
  "Октябрь", "Ноябрь", "Декабрь"};

vector<int> days_in_month = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

bool isLeap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getFirstDay(int year) {
  int day = year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
  day = day % 7;
  return day;
}

int main() {
  int year;
  cout << "Введите год: ";
  cin >> year;
  --year;
  
  if (isLeap(year)) {
    days_in_month[1] = 29;
  }
  
  int start_day = getFirstDay(year);
  
  for (int month = 0; month < 12; ++month) {
    cout << "\n\n---------------" << months[month] << "---------------\n";
    cout << "Пн Вт Ср Чт Пт Сб Вс\n";
    
    for (int i = 0; i < start_day; ++i) {
      cout << "   ";
    }
    
    for (int day = 1; day <= days_in_month[month]; ++day) {
      cout << setw(2) << day << " ";
      if (++start_day > 6) {
        start_day = 0;
        cout << "\n";
      }
    }
    
    if (start_day > 0) {
      cout << "\n";
    }
  }
  
  return 0;
}

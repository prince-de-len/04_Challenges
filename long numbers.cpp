/*************************************
* Codestyle: https://sun.iwu.edu/~mliffito/cs_codex/posts/google-c++-style-guide/
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 1
* Название: Длинные числа
* Ссылка: https://onlinegdb.com/dS4smjfgy
************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool AreEqual(string str_1, string str_2) {
  int num_1 = str_1.length(), num_2 = str_2.length();
  
  if (num_1 != num_2) {
    return false;
  }
  
  for (int index = 0; index < num_1; index++) {
    if (str_1[index] != str_2[index]) {
      return false;
    }
  }
  
  return true;
}

bool IsSmaller(string str_1, string str_2) {
  int num_1 = str_1.length(), num_2 = str_2.length();
  
  if (num_1 < num_2) {
    return true;
  }
  
  if (num_2 < num_1) {
    return false;
  }
  
  for (int index = 0; index < num_1; index++) {
    if (str_1[index] < str_2[index]) {
      return true;
    }
    else if (str_1[index] > str_2[index]) {
      return false;
    }
  }
  return false;
}

bool isGreater(string str_1, string str_2) {
  return !AreEqual(str_1, str_2) && !IsSmaller(str_1, str_2);
}


string Sum(string str_1, string str_2) {
  if (str_1.length() > str_2.length()) {
    swap(str_1, str_2);
  }
  
  string str = "";
  
  int num_1 = str_1.length(), num_2 = str_2.length();
  
  reverse(str_1.begin(), str_1.end());
  reverse(str_2.begin(), str_2.end());
  
  int carry = 0;
  for (int index = 0; index < num_1; index++) {
    int sum = ((str_1[index] - '0') + (str_2[index] - '0') + carry);
    str.push_back(sum % 10 + '0');
    
    carry = sum / 10;
  }
  
  for (int index = num_1; index < num_2; index++) {
    int sum = ((str_2[index] - '0') + carry);
    str.push_back(sum%10 + '0');
    carry = sum/10;
  }
  
  if (carry) {
    str.push_back(carry+'0');
  }
  
  reverse(str.begin(), str.end());
  
  return str;
}

string Multiply(string num_1, string num_2) {
  int len_1 = num_1.size();
  int len_2 = num_2.size();
  
  if (len_1 == 0 || len_2 == 0) {
    return "0";
  }
  
  vector<int> result(len_1 + len_2, 0);
  
  int position_num_1 = 0;
  int position_num_2 = 0;
  
  for (int index_1 = len_1-1; index_1 >= 0; index_1--) {
    int carry = 0;
    int digit_1 = num_1[index_1] - '0';
    
    position_num_2 = 0;
    
    for (int index_2 = len_2-1; index_2 >= 0; index_2--) {
      int digit_2 = num_2[index_2] - '0';
      
      int product = digit_1 * digit_2 + result[position_num_1 + position_num_2] + carry;
      
      carry = product / 10;
      
      result[position_num_1 + position_num_2] = product % 10;
      
      position_num_2++;
    }
    
    if (carry > 0) {
      result[position_num_1 + position_num_2] += carry;
    }
    
    position_num_1++;
  }
  
  int idx_result = result.size() - 1;
  while (idx_result >= 0 && result[idx_result] == 0) {
    idx_result--;
  }
  
  if (idx_result == -1) {
    return "0";
  }
  
  string product_str = "";
  
  while (idx_result >= 0) {
    product_str += to_string(result[idx_result--]);
  }
  
  return product_str;
}

string Subtract(string str_1, string str_2) {
  string str = "";
  
  int num_1 = str_1.length(), num_2 = str_2.length();
  
  reverse(str_1.begin(), str_1.end());
  reverse(str_2.begin(), str_2.end());
  
  int carry = 0;
  for (int index = 0; index < num_2 ; index++) {
    int sub = ((str_1[index]-'0')-(str_2[index]-'0')-carry);
    
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    }
    else
      carry = 0;
    
    str.push_back(sub + '0');
  }
  
  for (int index = num_2; index < num_1; index++) {
    int sub = ((str_1[index]-'0') - carry);
    
    if (sub < 0) {
      sub = sub + 10;
      carry = 1;
    }
    else {
      carry = 0;
    }
    
    str.push_back(sub + '0');
  }
  
  reverse(str.begin(), str.end());
  
  return str;
}

// делим большое число
string Division(string number, int divisor) {
  string ans;
  
  int idx = 0;
  int temp = number[idx] - '0';
  while (temp < divisor) {
    temp = temp * 10 + (number[++idx] - '0');
  }
  
  while (number.size() > idx) {
    ans += (temp / divisor) + '0';
    
    temp = (temp % divisor) * 10 + number[++idx] - '0';
  }
  
  if (ans.length() == 0) {
    return "0";
  }
  
  return ans;
}

int main() {
  string input_num_1, input_num_2;
  int input_num_2_divider, answer;
  char operation;
  
  cout << "Введите числа: " << endl;
  cin >> input_num_1 >> input_num_2;
  cout << "Введите операцию (+, -, *, /): " << endl;
  cin >> operation;
  
  cout << "Ответ: " << endl;
  switch(operation) {
    case '+':
      cout << Sum(input_num_1, input_num_2) << endl;
      break;
    case '-':
      cout << Subtract(input_num_1, input_num_2)<< endl;
      break;
    case '*':
      cout << Multiply(input_num_1, input_num_2) << endl;
      break;
    case '/':
      input_num_2_divider = stoi(input_num_2);
      cout << Division(input_num_1, input_num_2_divider)<< endl;
      break;
  }
  
  
  cout << "Введите числа для сравнения: " << endl;
  cin >> input_num_1 >> input_num_2;
  
  cout << "Введите операцию: " << endl;
  cin >> operation;
  
  cout << "Результат: " << endl;
  switch(operation) {
    case '<':
      answer = IsSmaller(input_num_1, input_num_2);
      break;
    case '>':
      answer = isGreater(input_num_1, input_num_2);
      break;
    case '=':
      answer = AreEqual(input_num_1, input_num_2);
      break;
  }
  
  if (answer == 1) {
    cout << "Верно" << endl;
  }
  else {
    cout << "Неверно" << endl;
  }
  return 0;
  
}

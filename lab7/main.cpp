#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 10;
vector<int> v;

// x = (x<0) ? 0 : x * 2
int f(int x) { return (x < 0) ? 0 : x * 2; }

// x != 0
bool c(int x) { return x != 0; }

void menu() {
  int inp;
  cout << endl << "Select menu item:" << endl;
  cout << "1: Print" << endl;
  cout << "2: Reverse" << endl;
  cout << "3: Transform" << endl;
  cout << "4: Count" << endl;
  cout << "0: Exit" << endl;

  cin >> inp;

  switch (inp) {
  case 1: {
    cout << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
      cout << *i << ' ';
    menu();
    break;
  };
  case 2: {
    reverse(v.begin(), v.end());
    menu();
    break;
  };
  case 3: {
    transform(v.begin(), v.end(), v.begin(), f);
    menu();
    break;
  };
  case 4: {
    cout << "x != 0: " << count_if(v.begin(), v.end(), c) << endl;
    menu();
    break;
  };
  case 0: {
    break;
  };
  default:
    cout << "Invalid Input";
    menu();
    break;
  }
}
int main() {
  srand(time(nullptr));

  for (int i = 0; i < LENGTH; i++) {
    int val = rand();
    v.push_back(val % 20 - 10);
  }

  menu();
  return 0;
}

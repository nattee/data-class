#include <iostream>
#include <stack>
#include <assert.h>
#include "stack.h"
#include "student.h"

typedef CP::stack<int> Stack;
using namespace std;


bool test1() {
  //pop
  Stack s;

  cout << s.size() << " " << s.empty() << endl;
  s.push(10);
  cout << s.size() << " " << s.empty() << endl;
  s.pop();
  cout << s.size() << " " << s.empty() << endl;

  return true;
}


bool test2() {
  CP::stack<string> s;
  for (int i= 0;i < 10;i++) {
    s.push("somchai");
    s.push("vishnu");
    s.push("nuttapong");
    s.push("nattee");
    cout << s.size() << " " << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << " " << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << " " << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << " " << s.empty() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << " " << s.empty() << endl;
  }
  return true;
}

bool test3() {
  Stack s;
  s.push(1);
  s.push(1);
  s.push(1);
  s.pop();
  s.pop();
  s.pop();

  Stack s2 = s;
  cout << s.size() << " " << s.empty() << endl;
  cout << s2.size() << " " << s2.empty() << endl;

  return true;
}

bool test4() {
  int nRun = 20;
  int nData = 100;
  Stack s;
  for (int i = 0;i < nRun;i++) {
    for (int j = 0;j < nData;j++) { s.push(j); }
    for (int j = 0;j < nData;j++) { s.pop(); }
    for (int j = 0;j < nData;j++) { s.push(j); }
  }
  for (int i = 0;i < 10;i++) {
    cout << s.top() << " " << s.size() << endl;
    s.pop();

  }
  return true;
}

bool test5() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.pop();
  s.pop();
  Stack s2(s);
  while (!s2.empty()) {
    cout << s2.top() << endl;
    s2.pop();
  }
  cout << s.size() << " " << s.empty() << endl;
  cout << s2.size() << " " << s2.empty() << endl;

  return true;
}
bool test6() {
  int n = 1000;
  Stack s1;
  for (int i = 0;i < n;i++) { s1.push(i); }
  for (int i = 0;i < n/2;i++) { s1.pop(); }
  Stack s2 = s1;
  while (!s1.empty()) { s1.pop(); }
  Stack s3(s1);
  s1.push(1);
  s2.push(1);
  s3.push(1);

  cout << s1.size() << " " << s1.empty() << " " << s1.top() << endl;
  cout << s2.size() << " " << s2.empty() << " " << s2.top() << endl;
  cout << s3.size() << " " << s3.empty() << " " << s3.top() << endl;
  return true;
}

bool test7() {
  int n = 10000000;
  Stack s1;
  for (int i = 0;i < n;i++) { s1.push(i); }
  for (int i = 0;i < n/2;i++) { s1.pop(); }
  Stack s2(s1);
  while (!s1.empty()) { s1.pop(); }
  Stack s3(s1);
  s1.push(1);
  s2.push(1);
  s3.push(1);

  cout << s1.size() << " " << s1.empty() << endl;
  cout << s2.size() << " " << s2.empty() << s2.top() << endl;
  cout << s3.size() << " " << s3.empty() << endl;
  return true;
}

bool test8() {
  Stack s;
  int n = 100;
  for (int j = 0;j < 10;j++) {
    for (int i = 0;i < n;i++) {
      s.deep_push(i,i);
    }
    for (int i = 0;i < n;i++) {
      cout << s.top() << " ";
      s.pop();
    }
  }
  return true;
}

bool test9() {
  Stack s;
  int n = 10;
  for (int j = 0;j < 10;j++) {
    std::vector<int> v;
    v.clear();
    for (int i = 0;i < n;i++) {
      s.deep_push(i,i);
      v.push_back(i*2);
    }
    s.multi_push(v);
  }
  while (!s.empty()) { 
    cout << s.top() << " ";
    s.pop();
  }
  return true;
}

bool test10() {
  Stack s;
  int n = 10;
  for (int j = 0;j < 10;j++) {
    std::vector<int> v;
    v.clear();
    for (int i = 0;i < n;i++) {
      s.deep_push(i,i);
      v.push_back(i*2);
    }
    s.multi_push(v);
  }
  for (int i = 0;i < 10;i++) {
    s.pop_until(2);
    cout << s.size() << " ";
    s.pop_until(8);
    cout << s.size() << " ";
    s.pop_until(5);
    cout << s.size() << " ";
    s.pop_until(1);
    cout << s.size() << " ";
  }
  while (!s.empty()) { 
    cout << s.top() << " ";
    s.pop();
  }
  return true;
}

int main() {
  int test_case;
  std::cin >> test_case;
  switch(test_case) {
    case 1: if (test1()) std::cout << "OK" << std::endl; break;
    case 2: if (test2()) std::cout << "OK" << std::endl; break;
    case 3: if (test3()) std::cout << "OK" << std::endl; break;
    case 4: if (test4()) std::cout << "OK" << std::endl; break;
    case 5: if (test5()) std::cout << "OK" << std::endl; break;
    case 6: if (test6()) std::cout << "OK" << std::endl; break;
    case 7: if (test7()) std::cout << "OK" << std::endl; break;
    case 8: if (test8()) std::cout << "OK" << std::endl; break;
    case 9: if (test9()) std::cout << "OK" << std::endl; break;
    case 10: if (test10()) std::cout << "OK" << std::endl; break;
  }

  return 0;
}

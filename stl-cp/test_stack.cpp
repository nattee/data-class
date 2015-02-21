#include <iostream>
#include <stack>
#include "stack.h"
#include <assert.h>
#include <exception>


//typedef CP::stack<int> Stack;
//
typedef CP::stack<int> Stack;

bool test1() {
  Stack s;
  assert(s.size() == 0);

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(3);
  
  assert(s.top() == 3 && s.size() == 4); s.pop();
  assert(s.top() == 3 && s.size() == 3); s.pop();
  assert(s.top() == 2 && s.size() == 2); s.pop();
  assert(s.top() == 1 && s.size() == 1); s.pop();

  assert(s.size() == 0);

  return true;
}

bool test2() {
  Stack s;
  s.push(1);
  s.push(1);
  s.push(1);
  s.pop();
  s.pop();
  s.pop();

  Stack s2 = s;

  try {
    int x = s.top();
    std::cout << "x = " << x << std::endl;
    s.pop();
  } catch (std::exception &e) {
    std::cout << "Caught an exception " << e.what() << std::endl;
    return true;
  }
  return false;
}

bool test3() {
  int nRun = 20;
  int nData = 1000000;
  for (int i = 0;i < nRun;i++) {
    Stack s;
    for (int j = 0;j < nData;j++) {
      s.push(j);
    }
    for (int j = 0;j < nData;j++) {
      s.pop();
    }
  }
  return true;
}

int main() {
  if (test1()) std::cout << "---------------------------------------- Test1 OK!" << std::endl;
  if (test2()) std::cout << "---------------------------------------- Test2 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test3 OK!" << std::endl;
//  if (test3()) std::cout << "---------------------------------------- Test4 OK!" << std::endl;


  return 0;
}

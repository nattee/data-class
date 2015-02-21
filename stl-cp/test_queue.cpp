#include <iostream>
#include <queue>
#include "queue.h"
#include <assert.h>
#include <exception>


//typedef CP::queue<int> Queue;
//
typedef CP::queue<int> Queue;

bool test1() {
  Queue q;
  assert(q.size() == 0);

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(3);

  assert(q.front() == 1 && q.size() == 4); q.pop();
  assert(q.front() == 2 && q.size() == 3); q.pop();
  assert(q.front() == 3 && q.size() == 2); q.pop();
  assert(q.front() == 3 && q.size() == 1); q.pop();

  assert(q.size() == 0);

  return true;
}

bool test2() {
  Queue q;
  q.push(1);
  q.push(1);
  q.push(1);
  q.pop();
  q.pop();
  q.pop();

  Queue s2 = q;

  try {
    int x = q.front();
    std::cout << "x = " << x << std::endl;
    q.pop();
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
    Queue q;
    for (int j = 0;j < nData;j++) {
      q.push(j);
    }
    for (int j = 0;j < nData;j++) {
      assert(q.front() == j);
      q.pop();
    }
  }
  return true;
}
bool test4() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.back() == 3);
    q.pop();
    q.push(4);
    assert(q.back() == 4);
    assert(q.front() == 2);
    q.pop();
    assert(q.front() == 3);
    q.pop();
    assert(q.back() == 4);
    assert(q.front() == 4);
    q.pop();
    if (q.size() == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
  if (test1()) std::cout << "---------------------------------------- Test1 OK!" << std::endl;
  if (test2()) std::cout << "---------------------------------------- Test2 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test3 OK!" << std::endl;
  if (test4()) std::cout << "---------------------------------------- Test4 OK!" << std::endl;
  return 0;
}

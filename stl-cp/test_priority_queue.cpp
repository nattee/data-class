 #include <iostream>
#include <assert.h>
#include <algorithm>
#include "priority_queue.h"


bool test1() {
  int value[] = {1,2,3,4,5,6,7,8};
  do {
    CP::priority_queue<int> q;
    for (int i = 0;i < 8;i++) {
      q.push(value[i]);
    }
    assert(q.top() == 8); q.pop();
    assert(q.top() == 7); q.pop();
    assert(q.top() == 6); q.pop();
    assert(q.top() == 5); q.pop();
    assert(q.top() == 4); q.pop();
    assert(q.top() == 3); q.pop();
    assert(q.top() == 2); q.pop();
    assert(q.top() == 1); q.pop();
  } while (std::next_permutation(value,value+8) );
  return true;
}

bool test2() {
  int value[] = {1,2,3,4,5,6,7,8};
  do {
    CP::priority_queue<int,std::greater<int>> q;
    for (int i = 0;i < 8;i++) {
      q.push(value[i]);
    }
    assert(q.top() == 1); q.pop();
    assert(q.top() == 2); q.pop();
    assert(q.top() == 3); q.pop();
    assert(q.top() == 4); q.pop();
    assert(q.top() == 5); q.pop();
    assert(q.top() == 6); q.pop();
    assert(q.top() == 7); q.pop();
    assert(q.top() == 8); q.pop();
  } while (std::next_permutation(value,value+8) );
  return true;
}

bool test3() {
  CP::priority_queue<int,std::greater<int>> q1;
  for (int i = 1;i <= 10;i++) q1.push(i);
  CP::priority_queue<int,std::greater<int>> q2 = q1;
  CP::priority_queue<int,std::greater<int>> q3;
  q3 = q2;

  assert(q1.top() == 1); q1.pop();
  assert(q1.top() == 2); q1.pop();
  assert(q1.top() == 3); q1.pop();
  assert(q1.top() == 4); q1.pop();
  assert(q1.top() == 5); q1.pop();
  assert(q1.top() == 6); q1.pop();
  assert(q1.top() == 7); q1.pop();
  assert(q1.top() == 8); q1.pop();
  assert(q1.size() == 2);
  assert(q1.top() == 9); q1.pop();
  assert(q1.top() == 10); q1.pop();
  assert(q1.empty());

  assert(q2.top() == 1); q2.pop();
  assert(q2.top() == 2); q2.pop();
  assert(q2.top() == 3); q2.pop();
  assert(q2.top() == 4); q2.pop();
  assert(q2.top() == 5); q2.pop();
  assert(q2.top() == 6); q2.pop();
  assert(q2.top() == 7); q2.pop();
  assert(q2.top() == 8); q2.pop();
  assert(q2.size() == 2);
  assert(q2.top() == 9); q2.pop();
  assert(q2.top() == 10); q2.pop();
  assert(q2.empty());

  assert(q3.top() == 1); q3.pop();
  assert(q3.top() == 2); q3.pop();
  assert(q3.top() == 3); q3.pop();
  assert(q3.top() == 4); q3.pop();
  assert(q3.top() == 5); q3.pop();
  assert(q3.top() == 6); q3.pop();
  assert(q3.top() == 7); q3.pop();
  assert(q3.top() == 8); q3.pop();
  assert(q3.size() == 2);
  assert(q3.top() == 9); q3.pop();
  assert(q3.top() == 10); q3.pop();
  assert(q3.empty());

  return true;
}

typedef bool(*CompFunctor)(const int&, const int&); // Function pointer type named "CompFunctor" 

bool Compare(const int &a,const int &b)    // The actual comparator function matching the CompFunctor signature
{
  return a > b;
}

bool Compare2(const int& a,const int & b) // The actual comparator function matching the CompFunctor signature
{
  return a < b;
}
bool test4() {
  //create two priority_queue with different comparator
  CP::priority_queue<int,CompFunctor> q(Compare);
  CP::priority_queue<int,CompFunctor> q2(Compare2);

  //add data
  for (int i = 0;i < 5;i++) {
    q.push(i);
    q2.push(i);
  }

  // check that q2 works as it should, popping out all data
  for (int i = 0;i < 5;i++) {
    assert(q2.top() == 5-i-1); q2.pop();
  }

  //copy q backt q2 (now q2 should be ordered according to q
  q2 = q;
  for (int i = 0;i < 5;i++) {
    assert(q.top() == i); q.pop();
    assert(q2.top() == i); q2.pop();
  }
  return true;

}

int main() {
  if (test1()) std::cout << "---------------------- Test 1 OK -----------------------" << std::endl;
  if (test2()) std::cout << "---------------------- Test 2 OK -----------------------" << std::endl;
  if (test3()) std::cout << "---------------------- Test 3 OK -----------------------" << std::endl;
  if (test4()) std::cout << "---------------------- Test 4 OK -----------------------" << std::endl;
}

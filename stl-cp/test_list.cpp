#include <iostream>
#include <assert.h>
#include "list.h"
#include <list>


bool test1() {
  CP::list<int> a;

  CP::list<int>::iterator it,it2;
  it =a.begin();
  it2 = it;
  it2++;
  assert(it == it2);
  a.push_back(10);
  it2++;
  assert(it != it2);
  a.push_back(11);
  a.push_back(12);
  a.push_back(30);
  a.push_back(99);
  a.print();

  a.clear();
  assert(a.size() == 0);
  a.push_front(1);
  a.push_front(2);
  a.push_front(3);
  a.push_front(4);
  a.push_front(5);
  a.pop_front();
  a.pop_back();
  a.print();

  assert(a.front() == 4);
  assert(a.back() == 2);

  return true;
}

bool test2() {
  CP::list<std::string> l,l2;
  l.push_back("AAA1");
  l.push_back("AAA2");
  l.push_back("AAA3");
  l.push_front("BBB");
  l2 = l;
  CP::list<std::string>::iterator it1,it2;
  it1 = l.begin();
  it2 = l2.begin();
  for (;it1 != l.end();it1++,it2++) {
    assert(*it1 == *it2);
  }
  l2.print();
  return true;
}

bool test3() {
  CP::list<std::pair<std::string,int> > l,l2;
  l.push_back(std::make_pair("A",1));
  l.push_back(std::make_pair("B",2));
  l.push_back(std::make_pair("C",3));
  l.push_back(std::make_pair("D",4));

  auto it = l.begin();
  it--;it--;

  for (size_t i = 0;i < l.size();i++) {
    l2.push_front(*it);
    it--;
  }
  for (auto& x: l2) {
    std::cout << x.first << ":" << x.second << std::endl;
  }

  return true;
}

int main() {
  if (test1()) std::cout << " ------------------------ TEST1 OK -------------------------" << std::endl;
  if (test2()) std::cout << " ------------------------ TEST2 OK -------------------------" << std::endl;
  if (test3()) std::cout << " ------------------------ TEST3 OK -------------------------" << std::endl;
}

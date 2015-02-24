#include "vector.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace CP;

bool test1() {
  size_t n = 10;
  CP::vector<int> myvector (n);   // 10 zero-initialized elements

  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector.at(sz-1-i);
    myvector[sz-1-i]=myvector[i];
    myvector.at(i)=temp;
  }

  assert(myvector.size() == n);

  int i = n-1;
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++,i--) {
    assert(*it == i);
  }

  return true;
}


class TempClass {
public:
  static int num;
  int myNum;

  std::string name;

  TempClass() {
    std::cout << std::setw(2);
    myNum = ++num;
    std::cout << (myNum) << ": [" << name << "] default constructed" << std::endl;
  }

  TempClass(const TempClass &c) {
    std::cout << std::setw(2);
    myNum = ++num;
    name = c.name;
    std::cout << (myNum) << ": [" << name << "] copy constructed" << std::endl;
  }

  TempClass(const std::string st) {
    std::cout << std::setw(2);
    myNum = ++num;
    name = st;
    std::cout << (myNum) << ": [" << name << "] custom constructed" << std::endl;
  }

  ~TempClass() {
    std::cout << std::setw(2);
    std::cout << myNum << ": [" << name << "] destructed" << std::endl;
  }

  TempClass& operator=(const TempClass &other) {
    this->name = other.name;
    return *this;

  }

  friend std::ostream& operator<<(std::ostream &os,const TempClass &c) {
    os << "My name is [" << c.name << "]";
    return os;
  }

  bool operator<(const TempClass &other) {
    return this->name < other.name;
  }

  bool operator==(const TempClass &other) {
    return this->name == other.name;
  }

};

int TempClass::num;

typedef CP::vector<TempClass> MyVector;

bool test2() {

  MyVector v(3);
  assert(v.size() == 3); assert(v.capacity() == 3);
  std::cout << "size = " << v.size() << " cap = " << v.capacity() << std::endl;
  v[0].name = "a";
  v[1].name = "b";
  v[2].name = "c";
  v.push_back(TempClass("1"));
  v.push_back(TempClass("2"));
  v.push_back(TempClass("3"));
  v.push_back(TempClass("4"));
  assert(v.size() == 7); assert(v.capacity() == 12);
  std::cout << "size = " << v.size() << " cap = " << v.capacity() << std::endl;
  for (MyVector::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  v.resize(2);
  assert(v.size() == 2); assert(v.capacity() == 12);
  assert(v[0].name == "a"); assert(v[1].name == "b");
  for (MyVector::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  v.clear();
  assert(v.size() == 0); assert(v.capacity() == 12);
  std::cout << "size = " << v.size() << " cap = " << v.capacity() << std::endl;
  return true;
}


bool test3() {
  MyVector v;
  v.insert(v.begin(),TempClass("1"));
  v.insert(v.begin(),TempClass("2"));
  v.insert(v.begin(),TempClass("3"));
  v.insert(v.begin()+1,TempClass("xxx"));
  assert(v[0].name == "3");
  assert(v[1].name == "xxx");
  assert(v[2].name == "2");
  assert(v[3].name == "1");
  for (MyVector::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  v.erase(v.end()-1);
  assert(v[0].name == "3");
  assert(v[1].name == "xxx");
  assert(v[2].name == "2");
  v.erase(v.begin());
  assert(v[0].name == "xxx");
  assert(v[1].name == "2");
  v.erase(v.end()-1);
  assert(v[0].name == "xxx");
  for (MyVector::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
  }
  return true;
}

bool test4() {
  MyVector v;
  v.push_back(TempClass("1"));
  v.push_back(TempClass("2"));
  v.push_back(TempClass("3"));
  v.push_back(TempClass("4"));

  MyVector::iterator it = std::find(v.begin(),v.end(),TempClass("2"));
  assert(it->name == "2");

  MyVector v2;
  v = v;
  v2 = v;

  v[0] = TempClass("5");
  assert(v[1] == v2[1]);
  assert(v[2] == v2[2]);
  assert(v[3] == v2[3]);
  assert(!(v[0] == v2[0]));

  return true;

}



int main() {
  if (test1()) std::cout << "---------------------------------------- Test1 OK!" << std::endl;
  if (test2()) std::cout << "---------------------------------------- Test2 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test3 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test4 OK!" << std::endl;


  return 0;
}

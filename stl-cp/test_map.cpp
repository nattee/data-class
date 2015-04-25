#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include "map_bst.h"
#include <assert.h>

bool test1() {
  CP::map_bst<int,std::string> m;
  m[10] = "A";
  m[8] = "B";
  m[6] = "C";
  m[11] = "D";
  m[12] = "E";

  m.print();
  m.insert(std::make_pair(13,"x"));
  m.insert(std::make_pair(7,"x"));
  m[5] = "E";
  m.print();
  m.erase(10);
  m.print();
  m.erase(8);
  m.print();
  m.erase(5);
  m.print();

  auto result = m.insert(std::make_pair(12,"x"));
  assert(result.second == false);
  while (result.first != m.end()) {
    std::cout << result.first->first << ": " << result.first->second << std::endl;
    result.first++;
  }
  return true;
}

bool test2() {
  CP::map_bst<int,bool> m;
  m[1] = m[2] = m[3] = m[4] = m[20] = m [11] = m[5] = m[9] = m[7] = false;
  m[-4] = m[-2] = m[-1] = m[-3] = true;
  for (auto& x : m) {
    std::cout << x.first << ": " << x.second << std::endl;
  }


  return true;
}

class TestClass {
  public:
    std::string   name;
    int           value;

    TestClass() : name(""), value(0) { }

    TestClass(std::string n, int v) : name(n), value(v) { }

    TestClass(const TestClass &other) : name(other.name), value(other.value) { }

    bool operator==(const TestClass& other) const {
      std::cout << "comparing " << (*this) << " and " << other << std::endl;
      return other.name == name && other.value == value;
    }

    bool operator<(const TestClass& other) const {
      return name < other.name;
    }

    friend std::ostream& operator<<(std::ostream& os,const TestClass& c) {
      os << "(name:" << c.name << ", value:" << c.value << ")";
      return os;
    }
};

bool comparator(const TestClass &a,const TestClass &b) {
  return a.name > b.name;
}

class ComparatorClass {
public:
  bool operator()(const TestClass &a,const TestClass &b) {
    return a.value < b.value;
  }
};

typedef bool(*CompFunc)(const TestClass&, const TestClass&); // Function pointer type named "CompFunctor" 

bool test3() {
  CP::map_bst<TestClass,float> m;
  CP::map_bst<TestClass,float> m2;

  m[TestClass("somchai",1)] = 0.1;
  m[TestClass("nuttapong",1)] = 1.1;
  m[TestClass("nattee",1)] = 2.2;
  m[TestClass("vishnu",1)] = 3.1;
  m.print();
  m[TestClass("somchai",1)] = 0.2;
  m[TestClass("somchai",2)] = 99;
  m.print();
  m[TestClass("xxx",1)] = 11;
  m[TestClass("x1",2)] = 23;
  m2 = m;
  m2.print();
  return true;
}

bool test4() {
  std::vector<std::pair<TestClass,float> > data;

  data.push_back(std::make_pair(TestClass("somchai",1),99));
  data.push_back(std::make_pair(TestClass("nuttapong",1),1.1));
  data.push_back(std::make_pair(TestClass("nattee",1),2.2));
  data.push_back(std::make_pair(TestClass("vishnu",1),3.1));
  data.push_back(std::make_pair(TestClass("xxx",1),11));
  data.push_back(std::make_pair(TestClass("x1",2),23));



  CP::map_bst<TestClass,float,ComparatorClass> m;
  for (auto& x : data) {
    m[x.first] = x.second;
  }
  m.print();

  CP::map_bst<TestClass,float,CompFunc> m2(comparator);
  for (auto& x : data) {
    m2[x.first] = x.second;
  }
  m2.print();

  return true;
}

int main() {

  if (test1()) std::cout << "-------------------- TEST 1 OK -------------------" << std::endl;
  if (test2()) std::cout << "-------------------- TEST 2 OK -------------------" << std::endl;
  if (test3()) std::cout << "-------------------- TEST 3 OK -------------------" << std::endl;
  if (test4()) std::cout << "-------------------- TEST 4 OK -------------------" << std::endl;
 
}

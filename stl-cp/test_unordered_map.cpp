#include <iostream>
#include <sstream>
#include <string>
#include "unordered_map_oa.h"
#include <unordered_map>


bool test1() {
  CP::unordered_map<std::string,std::string> mymap;

  std::cout << "size = " << mymap.size() << std::endl;
  std::cout << "bucket_count = " << mymap.bucket_count() << std::endl;
  std::cout << "load_factor = " << mymap.load_factor() << std::endl;

  mymap["Bakery"]="Barbara";  // new element inserted
  mymap["Seafood"]="Lisa";    // new element inserted
  mymap["Produce"]="John";    // new element inserted

  std::string name = mymap["Bakery"];   // existing element accessed (read)
  mymap["Seafood"] = name;              // existing element accessed (written)

  mymap["Bakery"] = mymap["Produce"];   // existing elements accessed (read/written)

  name = mymap["Deli"];      // non-existing element: new element "Deli" inserted!

  mymap["Produce"] = mymap["Gifts"];    // new element "Gifts" inserted, "Produce" written
  mymap["Gifts"] = "AAA";

  mymap.print();


  mymap.rehash(12);
  mymap.insert(std::make_pair("Test1","Test2"));
  mymap.print();

  //test iterator
  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }
  std::cout << "size = " << mymap.size() << std::endl;
  std::cout << "bucket_count = " << mymap.bucket_count() << std::endl;
  std::cout << "load_factor = " << mymap.load_factor() << std::endl;
  return true;
}




bool test2() {
  //test rehash
  CP::unordered_map<int,int> map;
  for (int i = 0;i < 25;i++) {
    map[i] = i*2;
  }

  //test iterator
  for (auto& x: map) {
    std::cout << x.first << ": " << x.second << std::endl;
  }
  std::cout << "size = " << map.size() << std::endl;
  std::cout << "bucket_count = " << map.bucket_count() << std::endl;
  std::cout << "load_factor = " << map.load_factor() << std::endl;
  return true;
}

class TestClass {
  public:
    std::string   name;
    int           value;

    TestClass() : name(""), value(0) { }

    TestClass(std::string n, int v) : name(n), value(v) { }

    bool operator==(const TestClass& other) const {
      return other.name == name && other.value == value;
    }

    friend std::ostream& operator<<(std::ostream& os,const TestClass& c) {
      os << "(name:" << c.name << ", value:" << c.value << ")";
      return os;
    }
};


class TestHasher {
public:
  std::size_t operator()(const TestClass &a) const {
    return a.value;
  }
};

class TestEqual {
  public:
    bool operator ()(const TestClass &a,const TestClass &b) const {
      return a.value == b.value;
    }
};

bool test3() {
  //test custom hash function with quadratic probing
  CP::unordered_map<TestClass,int,TestHasher,std::equal_to<TestClass>,CP::QuadraticProbing> map,map3;
  for (int i = 0;i < 12;i++) {
    std::stringstream s;
    s << "Test" << i;
    map[TestClass(s.str(),i%3)] = i*2;
  }
  map.print();

  //test custom equal function with linear probing
  CP::unordered_map<TestClass,int,TestHasher,TestEqual> map2;
  for (int i = 0;i < 12;i++) {
    std::stringstream s;
    s << "Test" << i;
    map2[TestClass(s.str(),i%3)] = i*2;
  }
  map2.print();
  map3 = map;
  map3.print();

  return true;

  map[1] = 2;
  map[2] = 3;
  map[3] = 4;
  map[4] = 5;
  map[5] = 6;
  map[6] = 7;
  map[7] = 8;
  map[8] = 9;
  map[9] = 10;
  map[10] = 11;
  map[11] = 12;
  map[12] = 13;
  map[13] = 14;
}

int main() {

  if (test1()) std::cout << "-------------------- TEST 1 OK -------------------" << std::endl;
  if (test2()) std::cout << "-------------------- TEST 2 OK -------------------" << std::endl;
  if (test3()) std::cout << "-------------------- TEST 3 OK -------------------" << std::endl;

}

#include "pair.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace CP;

bool test1() {
  //default constructor
  CP::pair<int,int> a;
  std::cout << "a = " << a.first << "," << a.second << std::endl;
  a.first = 1;
  a.second = 2;
  std::cout << "a = " << a.first << "," << a.second << std::endl;

  //copy constructor
  CP::pair<int,int> b(a);
  std::cout << "b = " << b.first << "," << b.second << std::endl;

  //assignment operator
  CP::pair<int,int> c;
  c = a;
  std::cout << "c = " << c.first << "," << c.second << std::endl;

  //custom constructor
  CP::pair<int,int> d(10,20);
  std::cout << "d = " << d.first << "," << d.second << std::endl;
  return true;
}



bool test2() {
  CP::pair<int,std::string> a(10,"vishnu");
  std::cout << "a = " << a.first << "," << a.second << std::endl;

  CP::pair<int,std::string> b(a);
  CP::pair<int,std::string> c;
  std::cout << "a == b? " << (a == b ? "YES" : "NO")  << std::endl;
  c = a;
  std::cout << "a == c? " << (a == c ? "YES" : "NO")  << std::endl;
  c.second = "abc";
  std::cout << "a == c? " << (a == c ? "YES" : "NO")  << std::endl;
  return true;
}


bool test3() {
  CP::pair<std::string,std::string> a,b,c;
  a.first   = "abc";
  a.second  = "hahaha";
  b = a;
  std::cout << "a < b? " << (a < b ? "YES" : "NO")  << std::endl;
  b.first = "def";
  std::cout << "a < b? " << (a < b ? "YES" : "NO")  << std::endl;

  c = a;
  c.second = "zzz";
  std::cout << "a < c? " << (a < b ? "YES" : "NO")  << std::endl;
  std::cout << "b < c? " << (b < b ? "YES" : "NO")  << std::endl;
  return true;
}

bool test4() {
  std::vector<CP::pair<int,std::string> > v;
  v.push_back( CP::pair<int,std::string>(10,"asdf"));
  v.push_back( CP::pair<int,std::string>(10,"zzz"));
  v.push_back( CP::pair<int,std::string>(10,"ddd"));
  v.push_back( CP::pair<int,std::string>(5,"asdf"));
  v.push_back( CP::pair<int,std::string>(3,"X"));
  v.push_back( CP::pair<int,std::string>(1,"asdf"));
  std::sort(v.begin(),v.end());
  for (size_t i = 0;i < v.size();i++) {
    std::cout << v[i].first << " " << v[i].second << std::endl;
  }
  return true;
}



int main() {
  if (test1()) std::cout << "---------------------------------------- Test1 OK!" << std::endl;
  if (test2()) std::cout << "---------------------------------------- Test2 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test3 OK!" << std::endl;
  if (test4()) std::cout << "---------------------------------------- Test4 OK!" << std::endl;
  return 0;
}

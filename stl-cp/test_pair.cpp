#include "pair.h"
#include <assert.h>
#include <iostream>
#include <string>

using namespace CP;

bool test1() {
  CP::pair<int,int> a;
  std::cout << "a = " << a.first << "," << a.second << std::endl;
  a.first = 1;
  a.second = 2;
  std::cout << "a = " << a.first << "," << a.second << std::endl;

  CP::pair<int,int> b(a);
  std::cout << "b = " << b.first << "," << b.second << std::endl;

  CP::pair<int,int> c;
  c = a;
  std::cout << "c = " << c.first << "," << c.second << std::endl;


  CP::pair<int,int> d(10,20);
  std::cout << "d = " << d.first << "," << d.second << std::endl;
  return true;
}



bool test2() {
  CP::pair<int,std::string> a;
  a.first = 10;
  a.second = "vishnu";
  std::cout << "a = " << a.first << "," << a.second << std::endl;

  CP::pair<int,std::string> b;
  b.first = 10;
  b.second = "vishnu";
  std::cout << "b = " << b.first << "," << b.second << std::endl;

  
  CP::pair<int,std::string> c;
  c = a;
  std::cout << "a == b? " << (a == c ? "YES" : "NO")  << std::endl;
  c.second = "abc";
  std::cout << "a == b? " << (a == c ? "YES" : "NO")  << std::endl;
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
  return true;
}



int main() {
  if (test1()) std::cout << "---------------------------------------- Test1 OK!" << std::endl;
  if (test2()) std::cout << "---------------------------------------- Test2 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test3 OK!" << std::endl;
  if (test3()) std::cout << "---------------------------------------- Test4 OK!" << std::endl;


  return 0;
}

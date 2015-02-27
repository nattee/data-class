#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v.back();
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  //write your code here
  if (depth > v.size()) depth = v.size();
  v.insert(v.end()-depth,element);
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  //write your code here
  for (auto &x : w)
    v.push_back(x);
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  //write your code here
  while (!v.empty() && v.back() != e) 
    v.pop_back();
}

#endif


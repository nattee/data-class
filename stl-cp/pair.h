#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP { 

template <typename T1,typename T2>
class pair
{
  public:
    T1  first;
    T2  second;

    // copy constructor
    pair(const pair<T1,T2>& a) {
      first = a.first;
      second = a.second;
    }

    // default constructor, using initializer list
    pair() : first() , second() { }

    // custom constructor, using initializer list
    pair(const T1 &a,const T2 &b) : first(a), second(b) { }

    // we have no destructor

    // copy assignment operator using traditional assignment
    pair<T1,T2>& operator=(const pair<T1,T2>& other) {
      first = other.first;
      second = other.second;
      return *this;
    }

    // equality operator
    bool operator==(const pair<T1,T2> &other) {
      return (first == other.first && second == other.second);
    }

    // comparison operator
    bool operator<(const pair<T1,T2> &other) {
      return ((first < other.first) ||
              (first == other.first && second < other.second));
    }

};

}

#endif



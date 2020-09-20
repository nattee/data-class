#ifndef _CP_PAIR_INCLUDED_
#define _CP_PAIR_INCLUDED_

//#include <stdexcept>
#include <iostream>

namespace CP { 

template <typename T1,typename T2>
class pair
{
  public:
    T1  first;
    T2  second;

    // default constructor, using list initialize
    pair() : first(), second() {}

    // custom constructor, using list initialize
    pair(const T1 &a,const T2 &b) : first(a), second(b) { }

    // we have no destructor

    // equality operator
    bool operator==(const pair<T1,T2> &other) {
      return (first == other.first && second == other.second);
    }

    // comparison operator
    bool operator<(const pair<T1,T2>& other) const {
      return ((first < other.first) ||
              (first == other.first && second < other.second));
    }

};


}

#endif



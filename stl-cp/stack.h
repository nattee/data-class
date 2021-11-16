#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP { 

template <typename T>
class stack
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
      if (capacity > mCap) {
        size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
        expand(s);
      }
    }

  public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
      this->mData = new T[a.mCap]();
      this->mCap = a.mCap;
      this->mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a.mData[i];
      }
    }

    // default constructor
    stack() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
    }

    // copy assignment operator
    stack<T>& operator=(stack<T> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      return *this;
    }

    ~stack() {
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    //----------------- access -----------------
    const T& top() const{
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[mSize-1];
    }

    //----------------- modifier -------------
    void push(const T& element) {  // Theta(n)
      ensureCapacity(mSize + 1);
      mData[mSize] = element;
      mSize++;
    }

    void pop() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      mSize--;
    }


};

}

#endif



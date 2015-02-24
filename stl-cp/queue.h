#ifndef _CP_QUEUE_INCLUDED_
#define _CP_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

namespace CP {

template <typename T>
class queue
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    size_t mFront;


    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[(mFront + i) % mCap];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
      mFront = 0;
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
    queue(const queue<T>& a) {
      this->mData = new T[a.mCap]();
      this->mCap = a.mCap;
      this->mSize = a.mSize;
      for (size_t i = 0; i < a.mCap;i++) {
        mData[i] = a.mData[i];
      }
      this->mFront = a.mFront;
    }

    // default constructor
    queue() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
      mFront = 0;
    }

    // copy assignment operator
    queue<T>& operator=(queue<T> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      return *this;
    }

    ~queue() {
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
    const T& front() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[mFront];
    }
    const T& back() const {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[(mFront + mSize - 1) % mCap];
    }

    //----------------- modifier -------------
    void push(const T& element) {
      ensureCapacity(mSize+1);
      mData[(mFront + mSize) % mCap] = element;
      mSize++;
    }

    void pop() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      mFront = (mFront + 1) % mCap;
      mSize--;
    }


};

}

#endif



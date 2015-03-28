#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>


namespace CP {

template <typename T,typename Comp = std::less<T> >
class priority_queue
{
  protected:
    T *mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

    void fixUp(size_t idx) {
      T tmp = mData[idx];
      while (idx > 0) {
        size_t p = (idx - 1) / 2;
        if ( mLess(tmp,mData[p]) ) break;
        mData[idx] = mData[p];
        idx = p;
      }
      mData[idx] = tmp;
    }

    void fixDown(size_t idx) {
      T tmp = mData[idx];
      size_t c;
      while ((c = 2 * idx + 1) < mSize) {
        if (c + 1 < mSize && mLess(mData[c],mData[c + 1]) ) c++;
        if ( mLess(mData[c],tmp) ) break;
        mData[idx] = mData[c];
        idx = c;
      }
      mData[idx] = tmp;
    }

    void print() {
      for (size_t i = 0;i < mSize;i++)
        std::cout << mData[i] << " ";
      std::cout << std::endl;
    }

  public:
    //-------------- constructor ----------

    // copy constructor
    priority_queue(priority_queue<T,Comp>& a) :
      mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mLess(a.mLess)
    {
      for (size_t i = 0; i < a.mCap;i++) {
        mData[i] = a.mData[i];
      }
    }

    // default constructor
    priority_queue(const Comp& c = Comp() ) :
       mData( new T[1]() ),
       mCap( 1 ),
       mSize( 0 ),
       mLess( c )
    { }


    // copy assignment operator
    priority_queue<T,Comp>& operator=(priority_queue<T,Comp> other) {
      using std::swap;
      swap(mSize,other.mSize);
      swap(mCap,other.mCap);
      swap(mData,other.mData);
      swap(mLess,other.mLess);
      return *this;
    }

    ~priority_queue() {
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
    const T& top() {
      if (size() == 0) throw std::out_of_range("index of out range") ;
      return mData[0];
    }

    //----------------- modifier -------------
    void push(const T& element) {
      if (mSize + 1 > mCap)
        expand(mCap * 2);
      mData[mSize] = element;
      mSize++;
      fixUp(mSize-1);
    }

    void pop() {
      if (size() == 0) throw std::out_of_range("index of out range");
      mData[0] = mData[mSize-1];
      mSize--;
      fixDown(0);
    }

    void erase(const T& v) {
      //erase v from the heap (if exists)
      //write your code here
    }

    void check_and_print() {
      //check HEAP
      for (int i =1;i < mSize;i++) {
        int p = (i-1)/2;
        if (mLess(mData[p],mData[i])) {
          printf("NOT A HEAP\n");
          return ;
        }
      }

      //print the heap
      while (!empty()) {
        std::cout << top() << " ";
        pop();
      }
      std::cout << std::endl;
    }
};

}

//---------------------------------------------
int main(int argc, char *argv[]) {

	char c = 0;
  CP::priority_queue<int> h;
	scanf("%c", &c);
  int v;
	while (c != 'q') {
		if (c == 'i') {
			// insert
			scanf("%d", &v);
      h.push(v);
		} else
		if (c == 'x') {
			// remove min
      h.pop();
		} else
		if (c == 'd') {
			// remove data
			scanf("%d", &v);
      h.erase(v);
		}
		scanf("%c", &c);
	}
	h.check_and_print();
  return 0;
}

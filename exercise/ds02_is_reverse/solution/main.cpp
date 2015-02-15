#include <stdexcept>
#include <iostream>

namespace CP { 

template <typename T>
class vector
{
  public:
    typedef T* iterator;

  protected:
    T *mData;
    size_t mCap;
    size_t mSize;

    void rangeCheck(int n) {
      if (n < 0 || (size_t)n >= mSize) {
        throw std::out_of_range("index of out range") ;
      }
    }

    void expand(size_t capacity) {
      T *arr = new T[capacity]();
      for (size_t i = 0;i < mSize;i++) {
        arr[i] = mData[i];
      }
      delete [] mData;
      mData = arr;
      mCap = capacity;
    }

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    vector(const vector<T>& a) {
      mData = new T[a.capacity()]();
      mCap = a.capacity();
      mSize = a.size();
      for (size_t i = 0;i < a.size();i++) {
        mData[i] = a[i];
      }
    }

    // default constructor
    vector() {
      int cap = 1;
      mData = new T[cap]();
      mCap = cap;
      mSize = 0;
    }

    // constructor with initial size
    vector(size_t cap) {
      mData = new T[cap]();
      mCap = cap;
      mSize = cap;
    }

    // copy assignment operator using copy-and-swap idiom
    vector<T>& operator=(vector<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mSize, other.mSize);
      swap(this->mCap, other.mCap);
      swap(this->mData, other.mData);
      return *this;
    }

    ~vector() {
      clear();
      delete [] mData;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }

    size_t capacity() const {
      return mCap;
    }

    void resize(size_t n) {
      if (n > mCap)
        expand(n);

      if (n > mSize) {
        T init = T();
        for (size_t i = mSize;i < n;i++) 
          mData[i] = init;
      }


      mSize = n;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return &mData[0];
    }

    iterator end() {
      return begin()+mSize;

    }
    //----------------- access -----------------
    T& at(int index) {
      rangeCheck(index);
      return mData[index];
    }

    T& at(int index) const {
      rangeCheck(index);
      return mData[index];
    }

    T& operator[](int index) {
      return mData[index];
    }

    T& operator[](int index) const {
      return mData[index];
    }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void pop_back() {
      mSize--;
    }

    iterator insert(iterator it,const T& element) {
      size_t pos = it - begin();
      if (mSize + 1 > mCap)
        expand(2 * mCap);
      for(size_t i = mSize;i > pos;i--) {
        mData[i] = mData[i-1];
      }
      mData[pos] = element;
      mSize++;
      return begin()+pos;
    }

    void erase(iterator it) {
      while((it+1)!=end()) {
        *it = *(it+1);
        it++;
      }
      mSize--;
    }

    void clear() {
      mSize = 0;
    }


    //-------------- extra (unlike STL) ------------------
    void insert_by_pos(size_t it,const T& element) {
      insert(begin()+it,element);
    }

    void erase_by_pos(int index) {
      erase(begin()+index);
    }

    void erase_by_value(const T& element) {
      int i = index_of(element);
      if (i != -1) erase_by_pos(i);
    }

    bool contains(const T& element) {
      return index_of(element) != -1;
    }

    int index_of(const T& element) {
      for (int i = 0;i < mSize;i++) {
        if (mData[i] == element) {
          return i;
        }
      }
      return -1;
    }

    bool isReverse(const vector<T> &other) const {
      //write your code only in this function
      if (mSize != other.mSize) return false;
      for (size_t i = 0;i < mSize;i++) {
        if (mData[i] != other[mSize-i-1]) return false;
      }
      return true;
    }
};

} // end namespace

bool equal(CP::vector<int> &a,CP::vector<int> &b) {
  if (a.size() != b.size()) return false;
  for (size_t i = 0;i < a.size();i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main() {
  int n,m;
  std::cin >> n >> m;

  //read input
  CP::vector<int> a,b;
  while (n--) {
    int tmp;
    std::cin >> tmp;
    a.push_back(tmp);
  }
  while (m--) {
    int tmp;
    std::cin >> tmp;
    b.push_back(tmp);
  }

  //check
  CP::vector<int> c;
  c = b;
  std::cout << a.isReverse(b) << std::endl;
  std::cout << equal(c,b) << std::endl;
  c = a;
  std::cout << b.isReverse(a) << std::endl;
  std::cout << equal(c,a) << std::endl;
}


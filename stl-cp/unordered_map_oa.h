#ifndef _CP_UNORDERED_MAP_SP_INCLUDED_
#define _CP_UNORDERED_MAP_SP_INCLUDED_

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <functional> // <--- define the default hasher and equal_to
#include <vector>
//#pragma once

namespace CP {

const size_t N_PRIMES = 256;
const unsigned long PRIMES[256] = {
  2ul, 3ul, 5ul, 7ul, 11ul, 13ul, 17ul, 19ul, 23ul, 29ul, 31ul,
  37ul, 41ul, 43ul, 47ul, 53ul, 59ul, 61ul, 67ul, 71ul, 73ul, 79ul,
  83ul, 89ul, 97ul, 103ul, 109ul, 113ul, 127ul, 137ul, 139ul, 149ul,
  157ul, 167ul, 179ul, 193ul, 199ul, 211ul, 227ul, 241ul, 257ul,
  277ul, 293ul, 313ul, 337ul, 359ul, 383ul, 409ul, 439ul, 467ul,
  503ul, 541ul, 577ul, 619ul, 661ul, 709ul, 761ul, 823ul, 887ul,
  953ul, 1031ul, 1109ul, 1193ul, 1289ul, 1381ul, 1493ul, 1613ul,
  1741ul, 1879ul, 2029ul, 2179ul, 2357ul, 2549ul, 2753ul, 2971ul,
  3209ul, 3469ul, 3739ul, 4027ul, 4349ul, 4703ul, 5087ul, 5503ul,
  5953ul, 6427ul, 6949ul, 7517ul, 8123ul, 8783ul, 9497ul, 10273ul,
  11113ul, 12011ul, 12983ul, 14033ul, 15173ul, 16411ul, 17749ul,
  19183ul, 20753ul, 22447ul, 24281ul, 26267ul, 28411ul, 30727ul,
  33223ul, 35933ul, 38873ul, 42043ul, 45481ul, 49201ul, 53201ul,
  57557ul, 62233ul, 67307ul, 72817ul, 78779ul, 85229ul, 92203ul,
  99733ul, 107897ul, 116731ul, 126271ul, 136607ul, 147793ul,
  159871ul, 172933ul, 187091ul, 202409ul, 218971ul, 236897ul,
  256279ul, 277261ul, 299951ul, 324503ul, 351061ul, 379787ul,
  410857ul, 444487ul, 480881ul, 520241ul, 562841ul, 608903ul,
  658753ul, 712697ul, 771049ul, 834181ul, 902483ul, 976369ul,
  1056323ul, 1142821ul, 1236397ul, 1337629ul, 1447153ul, 1565659ul,
  1693859ul, 1832561ul, 1982627ul, 2144977ul, 2320627ul, 2510653ul,
  2716249ul, 2938679ul, 3179303ul, 3439651ul, 3721303ul, 4026031ul,
  4355707ul, 4712381ul, 5098259ul, 5515729ul, 5967347ul, 6456007ul,
  6984629ul, 7556579ul, 8175383ul, 8844859ul, 9569143ul, 10352717ul,
  11200489ul, 12117689ul, 13109983ul, 14183539ul, 15345007ul,
  16601593ul, 17961079ul, 19431899ul, 21023161ul, 22744717ul,
  24607243ul, 26622317ul, 28802401ul, 31160981ul, 33712729ul,
  36473443ul, 39460231ul, 42691603ul, 46187573ul, 49969847ul,
  54061849ul, 58488943ul, 63278561ul, 68460391ul, 74066549ul,
  80131819ul, 86693767ul, 93793069ul, 101473717ul, 109783337ul,
  118773397ul, 128499677ul, 139022417ul, 150406843ul, 162723577ul,
  176048909ul, 190465427ul, 206062531ul, 222936881ul, 241193053ul,
  260944219ul, 282312799ul, 305431229ul, 330442829ul, 357502601ul,
  386778277ul, 418451333ul, 452718089ul, 489790921ul, 529899637ul,
  573292817ul, 620239453ul, 671030513ul, 725980837ul, 785430967ul,
  849749479ul, 919334987ul, 994618837ul, 1076067617ul, 1164186217ul,
  1259520799ul, 1362662261ul, 1474249943ul, 1594975441ul,
  1725587117ul, 1866894511ul, 2019773507ul, 2185171673ul,
  2364114217ul, 2557710269ul, 2767159799ul, 2993761039ul,
  3238918481ul, 3504151727ul, 3791104843ul, 4101556399ul,
  4294967291ul,
};


class LinearProbing
{
public:
  size_t operator()(size_t initial_pos, size_t col_count, size_t bucket_count) {
    return (initial_pos+col_count) % bucket_count;
  }
};


class QuadraticProbing
{
public:
  size_t operator()(size_t initial_pos, size_t col_count, size_t bucket_size) {
    return (initial_pos+col_count*col_count) % bucket_size;
  }
};

template <typename KeyT,
          typename MappedT,
          typename HasherT = std::hash<KeyT>,
          typename EqualT = std::equal_to<KeyT>,
          typename NextAddressT = LinearProbing >
class unordered_map
{
  protected:

    typedef std::pair<KeyT,MappedT>                 ValueT;

    class BucketT {
    public:
      ValueT value;
      unsigned char status; // 0 = no data, 1 = deleted , 2 = has data

      bool available() { return status < 2; }
      bool empty() { return status == 0; }
      bool has_data() { return status == 2; }
      void mark_deleted() { status = 1; }
      void mark_empty() { status = 0; }
      void mark_data() { status = 2;}
    };

    typedef typename std::vector<BucketT>::iterator BucketIterator;

    //-------------------------------------------------------------
    class hashtable_iterator {
      protected:
        BucketIterator mCurBucketItr;
        BucketIterator mEndBucketItr;

        void to_next_data() {
          while (mCurBucketItr != mEndBucketItr &&
                 !mCurBucketItr->has_data()) {
            mCurBucketItr++;
          }
        }

      public:
        typedef ValueT &reference;
        typedef ValueT *pointer;

        hashtable_iterator(BucketIterator bucket,BucketIterator endBucket) :
          mCurBucketItr(bucket), mEndBucketItr(endBucket) {
            to_next_data();
        }

        hashtable_iterator() { }

        hashtable_iterator& operator++() {
          mCurBucketItr++;
          to_next_data();
          return (*this);
        }
        hashtable_iterator operator++(int) {
          hashtable_iterator tmp(*this);
          operator++();
          return tmp;
        }

        reference operator*() {
          return mCurBucketItr->value;
        }

        pointer operator->() {
          return &(*mCurBucketItr).value;
        }

        bool operator!=(const hashtable_iterator &other) {
          return (this->mCurBucketItr != other.mCurBucketItr);
        }

        bool operator==(const hashtable_iterator &other) {
            return !((*this) != other);
        }
    };
    //-------------------------------------------------------------
    std::vector<BucketT> mBuckets;
    size_t               mSize;
    HasherT              mHasher;
    EqualT               mEqual;
    float                mMaxLoadFactor;
    size_t               mUsed;
    NextAddressT         mNextAddress;

  public:
    typedef hashtable_iterator iterator;

  protected:
    void rangeCheck(int n) {
      if (n < 0 || (size_t)n >= mSize) {
        throw std::out_of_range("index of out range") ;
      }
    }

    size_t find_position(const KeyT& key) {
      size_t homePos = hash_to_bucket(key);
      size_t pos = homePos;
      size_t col_count = 0;
      while (!mBuckets[pos].empty() && !mEqual(mBuckets[pos].value.first,key)) {
        pos = mNextAddress(homePos,++col_count,bucket_count());
      }
      return pos;
    }

    size_t hash_to_bucket(const KeyT& key) {
      return mHasher(key) % mBuckets.size();
    }

    BucketIterator insert_to_position(const ValueT& val, size_t& pos) {
      if (load_factor() > max_load_factor()) {
        rehash(2*bucket_count());
        pos = find_position(val.first);
      }
      mBuckets[pos].value = val;
      if (mBuckets[pos].empty()) mUsed++;
      mBuckets[pos].mark_data();
      mSize++;
      return mBuckets.begin()+pos;
    }

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    unordered_map(const unordered_map<KeyT,MappedT,HasherT,EqualT,NextAddressT> &other) :
      mBuckets(other.mBuckets), mSize(other.mSize),
      mHasher(other.mHasher), mEqual(other.mEqual),
      mMaxLoadFactor(other.mMaxLoadFactor),
      mUsed(other.mUsed),mNextAddress(other.mNextAddress)

    { }

    // default constructor
    unordered_map() :
      mBuckets( std::vector<BucketT>(11) ), mSize(0),
      mHasher( HasherT() ), mEqual( EqualT() ), mMaxLoadFactor(0.7),
      mUsed(0), mNextAddress( NextAddressT() )
    { }

    // copy assignment operator using copy-and-swap idiom
    unordered_map<KeyT,MappedT,HasherT,EqualT,NextAddressT>& 
    operator=(unordered_map<KeyT,MappedT,HasherT,EqualT,NextAddressT> other)  {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be destructed
      using std::swap;
      swap(this->mBuckets,        other.mBuckets);
      swap(this->mSize,           other.mSize   );
      swap(this->mHasher,         other.mHasher );
      swap(this->mEqual,          other.mEqual  );
      swap(this->mMaxLoadFactor,  other.mMaxLoadFactor);
      swap(this->mUsed,           other.mUsed);
      swap(this->mNextAddress,    other.mNextAddress);
      return *this;
    }

    ~unordered_map() {
      clear();
    }

    //------------- capacity function -------------------
    bool empty() {
      return mSize == 0;
    }

    size_t size() {
      return mSize;
    }

    size_t bucket_count() {
      return mBuckets.size();
    }

    size_t bucket_size(size_t n) {
      return mBuckets[n].has_data() ? 1 : 0;
    }

    float load_factor() {
      return (float)mUsed/mBuckets.size();
    }
    float max_load_factor() {
      return mMaxLoadFactor;
    }
    void max_load_factor(float z) {
      mMaxLoadFactor = z;
      rehash(bucket_count());
    }

    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mBuckets.begin(),
                      mBuckets.end());
    }

    iterator end() {
      return iterator(mBuckets.end(),
                      mBuckets.end());
    }

    //----------------- access -----------------
    MappedT& operator[](const KeyT& key) {
      size_t pos = find_position(key);
      if (mBuckets[pos].available()) {
        BucketIterator it = insert_to_position(std::make_pair(key, MappedT()),pos);
      }
      return mBuckets[pos].value.second;
    }

    //----------------- modifier -------------

    std::pair<iterator,bool> insert(const ValueT& val) {
      std::pair<iterator,bool> result;
      size_t pos = find_position(val.first);
      if (mBuckets[pos].available()) {
        BucketIterator it = insert_to_position(val,pos);
        result.first = iterator(it,mBuckets.end());
        result.second = true;
      } else {
        result.first = iterator(mBuckets.begin()+pos,mBuckets.end());
        result.second = false;
      }
      return result;
    }

    size_t erase(const KeyT &key) {
      size_t pos = find_position(key);
      if (mBuckets[pos].has_data()) {
        mBuckets[pos].mark_deleted();
        mSize--;
        return 1;
      } else return 0;
    }

    void clear() {
      for (auto& bucket : mBuckets) {
        bucket.mark_empty();
      }
      mSize = 0;
      mUsed = 0;
    }

    void rehash(size_t n) {
      if (load_factor() <= max_load_factor() && n <= mBuckets.size()) return;
      n = std::max(n, mBuckets.size()*2);
      n = *std::lower_bound(PRIMES,PRIMES+N_PRIMES,n);

      std::vector<ValueT> tmp;
      for (auto& val : *this) {
        tmp.push_back(val);
      }
      this->clear();
      mBuckets.resize(n);
      for (auto& val : tmp) {
        this->insert(val);
      }
    }

    void print() {
      std::cout << "------------------------------------------" << std::endl;
      std::cout << "Size = " << size() << std::endl;
      std::cout << "bucket count = " << bucket_count() << std::endl;
      std::cout << "load factor = " << load_factor() << std::endl;
      std::cout << "max load factor = " << max_load_factor() << std::endl;
      for (size_t i = 0;i < mBuckets.size();i++) {
        std::cout << "  bucket #" << std::setw(3) << i;
        if (mBuckets[i].status == 0) std::cout << "[----]";
        else if (mBuckets[i].status == 1) std::cout << "[-- DELETED --]";
        else std::cout << "    [" << mBuckets[i].value.first << ", " << mBuckets[i].value.second << "]";
        std::cout << std::endl;
      }
    }

};

}

#endif

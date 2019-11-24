#ifndef _CP_MAP_AVL_INCLUDED_
#define _CP_MAP_AVL_INCLUDED_

#include <iostream>
#include <assert.h>
//#pragma once

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename CompareT = std::less<KeyT> >
class map_avl
{
  protected:

    typedef std::pair<KeyT,MappedT> ValueT;

    class node {
      friend class map_avl;
      protected:
        ValueT data;
        node  *left;
        node  *right;
        node  *parent;
        int    height;

        node() :
          data( ValueT() ), left( NULL ), right( NULL ), parent( NULL ), height(0) { }

        node(const ValueT& data, node* left, node* right, node* parent) :
          data ( data ), left( left ), right( right ), parent( parent ) {
            set_height();
        }

        int get_height(node *n) { // ไม่ OO ?
            return (n == NULL ? -1 : n->height);
        }
        void set_height() {
            int hL = get_height(this->left);
            int hR = get_height(this->right);
            height = 1 + (hL > hR ? hL : hR);
        }
        int balance_value() {
            return get_height(this->right) - get_height(this->left);
        }
        void set_left(node *n) {
            this->left = n;
            if (n != NULL) this->left->parent = this;
        }
        void set_right(node *n) {
            this->right = n;
            if (n != NULL) this->right->parent = this;
        }
    };

    //-------------------------------------------------------------
    class tree_iterator {
      protected:
        node* ptr;

      public:
        tree_iterator() : ptr( NULL ) { }

        tree_iterator(node *a) : ptr(a) { }

        tree_iterator& operator++() {
          if (ptr->right == NULL) {
            node *parent = ptr->parent;
            while (parent != NULL && parent->right == ptr) {
              ptr = parent;
              parent = ptr->parent;
            }
            ptr = parent;
          } else {
            ptr = ptr->right;
            while (ptr->left != NULL)
              ptr = ptr->left;
          }
          return (*this);
        }

        tree_iterator& operator--() {
          if (ptr->left == NULL) {
            node *parent = ptr->parent;
            while (parent != NULL && parent->left == ptr) {
              ptr = parent;
              parent = ptr->parent;
            }
            ptr = parent;
          } else {
            ptr = ptr->left;
            while (ptr->right != NULL)
              ptr = ptr->right;
          }
          return (*this);
        }

        tree_iterator operator++(int) {
          tree_iterator tmp(*this);
          operator++();
          return tmp;
        }

        tree_iterator operator--(int) {
          tree_iterator tmp(*this);
          operator--();
          return tmp;
        }

        ValueT& operator*()  { return ptr->data;    }
        ValueT* operator->() { return &(ptr->data); }
        bool    operator==(const tree_iterator& other) { return other.ptr == ptr; }
        bool    operator!=(const tree_iterator& other) { return other.ptr != ptr; }
    };

   //-------------------------------------------------------------
    node     *mRoot;
    CompareT  mLess;
    size_t    mSize;

  public:
    typedef tree_iterator iterator;

  protected:
    int compare(const KeyT& k1, const KeyT& k2) {
      if (mLess(k1, k2)) return -1;
      if (mLess(k2, k1)) return +1;
      return 0;
    }
    node * find_node(const KeyT & key, node *r, node *&parent) {
      if (r == NULL) return NULL;
      int cmp = compare(key, r->data.first);
      if (cmp == 0) return r;
      parent = r;
      return find_node(key, cmp < 0 ? r->left : r->right, parent);
    }
    node* find_min_node(node* r) {
      //r must not be NULL
      node *min = r;
      while (min->left != NULL) {
        min = min->left;
      }
      return min;
    }
    node* find_max_node(node* r) {
      //r must not be NULL
      node *max = r;
      while (max->right != NULL) {
        max = max->right;
      }
      return max;
    }
    node* copy(node* src, node* parent) {
        if (src == NULL) return NULL;
        node* tmp   = new node();
        tmp->data   = src->data;
        tmp->left   = copy(src->left,  tmp);
        tmp->right  = copy(src->right, tmp);
        tmp->parent = parent;
        return tmp;
    }
    void delete_all_nodes(node *r) {
        if (r == NULL) return;
        delete_all_nodes(r->left);
        delete_all_nodes(r->right);
        delete r;
    }
    node * rotate_left_child(node * r) {
        node * new_root = r->left;
        r->set_left(new_root->right);
        new_root->set_right(r);
        new_root->right->set_height();
        new_root->set_height();
        return new_root;
    }
    node * rotate_right_child(node * r) {
        node * new_root = r->right;
        r->set_right(new_root->left);
        new_root->set_left(r);
        new_root->left->set_height();
        new_root->set_height();
        return new_root;
    }
    node * rebalance(node * r) {
        if (r == NULL) return r;
        int balance = r->balance_value();
        if (balance == -2) {
            if (r->left->balance_value() == 1) {
                r->set_left(rotate_right_child(r->left));
            }
            r = rotate_left_child(r);
        } else if (balance == 2) {
            if (r->right->balance_value() == -1) {
                r->set_right(rotate_left_child(r->right));
            }
            r = rotate_right_child(r);
        }
        r->set_height();
        return r;
    }
    node* insert(const ValueT& val, node *r, node * &ptr) {
      if (r == NULL) {
        mSize++;
        ptr = r = new node(val,NULL,NULL,NULL);
      } else {
        int cmp = compare(val.first, r->data.first);
        if (cmp == 0) ptr = r;
        else if (cmp <  0) {
            r->set_left(insert(val, r->left, ptr));
        } else {
            r->set_right(insert(val, r->right, ptr));
        }
      }
      r = rebalance(r);
      return r;
    }
    node *erase(const KeyT &key, node *r) {
      if (r == NULL) return NULL;
      int cmp = compare(key, r->data.first);
      if (cmp < 0) {
        r->set_left(erase(key, r->left));
      } else if (cmp > 0) {
        r->set_right(erase(key, r->right));
      } else {
        if (r->left == NULL || r->right == NULL) {
            node *n = r;
            r = (r->left == NULL ? r->right : r->left);
            delete n;
            mSize--;
        } else {
            node * m = r->right;
            while (m->left != NULL) m = m->left;
            std::swap(r->data.first, m->data.first);
            std::swap(r->data.second, m->data.second);
            r->set_right(erase(m->data.first, r->right));
        }
      }
      r = rebalance(r);
      return r;
    }
  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    map_avl(const map_avl<KeyT,MappedT,CompareT> & other) :
      mLess(other.mLess) , mSize(other.mSize)
    {
        mRoot = copy(other.mRoot, NULL);
    }

    // default constructor
    map_avl(const CompareT& c = CompareT() ) :
      mRoot(NULL), mLess(c) , mSize(0)
    { }

    // copy assignment operator using copy-and-swap idiom
    map_avl<KeyT,MappedT,CompareT>& operator=(map_avl<KeyT,MappedT,CompareT> other)  {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be destructed
      using std::swap;
      swap(this->mRoot, other.mRoot);
      swap(this->mLess, other.mLess);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~map_avl() {
      clear();
    }

    bool empty() {
      return mSize == 0;
    }

    size_t size() {
      return mSize;
    }

    iterator begin() {
      return iterator(mRoot==NULL ? NULL : find_min_node(mRoot));
    }

    iterator end() {
      return iterator(NULL);
    }

    iterator find(const KeyT &key) {
      node *parent = NULL;
      node *ptr = find_node(key, mRoot, parent);
      return ptr == NULL ? end() : iterator(ptr);
    }

    void clear() {
      delete_all_nodes(mRoot);
      mRoot = NULL;
      mSize = 0;
    }

    MappedT& operator[](const KeyT& key) {
      std::pair<iterator,bool> result = insert(std::make_pair(key,MappedT()));
      return result.first->second;
    }

    std::pair<iterator,bool> insert(const ValueT& val) {
      node *ptr = NULL;
      size_t s = mSize;
      mRoot = insert(val, mRoot, ptr);
      mRoot->parent = NULL;
      return std::make_pair(iterator(ptr),(mSize > s));
    }

    size_t erase(const KeyT &key) {
      size_t s = mSize;
      mRoot = erase(key, mRoot);
      return s == mSize ? 0 : 1;
    }
    //----------------------------------------------------------------
    void print_node(node *n,size_t depth) {
      if (n != NULL) {
        if (n->right != NULL && n->right->parent != n)
          std::cout << "parent of " << n->right->data.first << std::endl;
        if (n->left != NULL && n->left->parent != n)
          std::cout << "parent of " << n->left->data.first << std::endl;
        print_node(n->right,depth+1);
        for (size_t i = 0;i < depth;i++) std::cout << "--";
        std::cout << " " << n->data.first << ":" << n->data.second << std::endl;
        print_node(n->left,depth+1);
      }
    }

    void print() {
      std::cout << " ======== size = " << mSize << " ========= " << std::endl;
      print_node(mRoot,0);
    }
    bool checkParent() {
        return checkParent(mRoot);
    }
    bool checkParent(node *r) {
        if (r == NULL) return true;
        if (r->left != NULL && r != r->left->parent) return false;
        if (r->right != NULL && r != r->right->parent) return false;
        if (!checkParent(r->left)) return false;
        return checkParent(r->right);
    }
    bool checkInorder() {
        return checkInorder(mRoot);
    }
    bool checkInorder(node *r) {
        if (r==NULL) return true;
        if (r->left != NULL && !mLess(r->left->data.first,r->data.first)) return false;
        if (r->right != NULL && !mLess(r->data.first, r->right->data.first)) return false;
        if (!checkInorder(r->left)) return false;
        return checkInorder(r->right);
    }
    int height(node *r) {
        if (r == NULL) return -1;
        int hl = height(r->left);
        int hr = height(r->right);
        return 1 + (hl > hr ? hl : hr);
    }
    int height() {
        if (mRoot == NULL) return -1;
        assert(height(mRoot) == mRoot->height);
        return mRoot->height;
    }
};

}

#endif

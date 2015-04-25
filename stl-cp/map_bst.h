#ifndef _CP_MAP_BST_INCLUDED_
#define _CP_MAP_BST_INCLUDED_

#include <iostream>
//#pragma once

namespace CP {

template <typename KeyT,
          typename MappedT,
          typename CompareT = std::less<KeyT> >
class map_bst
{
  protected:

    typedef std::pair<KeyT,MappedT> ValueT;

    class node {
      friend class map_bst;
      protected:
        ValueT data;
        node  *left;
        node  *right;
        node  *parent;

        node() :
          data( ValueT() ), left( NULL ), right( NULL ), parent( NULL ) { }

        node(const ValueT& data, node* left, node* right, node* parent) :
          data ( data ), left( left ), right( right ), parent( parent ) { }
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
    node* &child_link(node* parent, const KeyT& k) {
        if (parent == NULL) return mRoot;
        return mLess(k, parent->data.first) ?
               parent->left : parent->right;
    }
    int compare(const KeyT& k1, const KeyT& k2) {
      if (mLess(k1, k2)) return -1;
      if (mLess(k2, k1)) return +1;
      return 0;
    }
    node* find_node(const KeyT& k,node* r, node* &parent) {
      node *ptr = r;
      while (ptr != NULL) {
        int cmp = compare(k, ptr->data.first);
        if (cmp == 0) return ptr;
        parent = ptr;
        ptr = cmp < 0 ? ptr->left : ptr->right;
      }
      return NULL;
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

  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    map_bst(const map_bst<KeyT,MappedT,CompareT> & other) :
      mLess(other.mLess) , mSize(other.mSize)
    {
        mRoot = copy(other.mRoot, NULL);
    }

    // default constructor
    map_bst(const CompareT& c = CompareT() ) :
      mRoot(NULL), mLess(c) , mSize(0)
    { }

    // copy assignment operator using copy-and-swap idiom
    map_bst<KeyT,MappedT,CompareT>& operator=(map_bst<KeyT,MappedT,CompareT> other)  {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be destructed
      using std::swap;
      swap(this->mRoot, other.mRoot);
      swap(this->mLess, other.mLess);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~map_bst() {
      clear();
    }

    //------------- capacity function -------------------
    bool empty() {
      return mSize == 0;
    }

    size_t size() {
      return mSize;
    }

    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mRoot==NULL ? NULL : find_min_node(mRoot));
    }

    iterator end() {
      return iterator(NULL);
    }

    //----------------- modifier -------------
    void clear() {
      delete_all_nodes(mRoot);
      mRoot = NULL;
      mSize = 0;
    }

    MappedT& operator[](const KeyT& key) {
      node *parent = NULL;
      node *ptr = find_node(key, mRoot, parent);
      if (ptr == NULL) {
        ptr = new node(std::make_pair(key,MappedT()),NULL,NULL,parent);
        child_link(parent, key) = ptr;
        mSize++;
      }
      return ptr->data.second;
    }

    std::pair<iterator,bool> insert(const ValueT& val) {
      node *parent = NULL;
      node *ptr = find_node(val.first,mRoot,parent);
      bool not_found = (ptr==NULL);
      if (not_found) {
        ptr = new node(val,NULL,NULL,parent);
        child_link(parent, val.first) = ptr;
        mSize++;
      }
      return std::make_pair(iterator(ptr), not_found);
    }

    iterator find(const KeyT &key) {
      node *parent;
      node *ptr = find_node(key,mRoot,parent);
      return ptr == NULL ? end() : iterator(ptr);
    }

    size_t erase(const KeyT &key) {
      if (mRoot == NULL) return 0;

      node *parent = NULL;
      node *ptr = find_node(key,mRoot,parent);
      if (ptr == NULL) return 0;
      if (ptr->left != NULL && ptr->right != NULL) {
          //have two children
        node *min = find_min_node(ptr->right);
        node * &link = child_link(min->parent, min->data.first);
        link = (min->left == NULL) ? min->right : min->left;
        if (link != NULL) link->parent = min->parent;
        std::swap(ptr->data.first, min->data.first);
        std::swap(ptr->data.second, min->data.second);
        ptr = min; // we are going to delete this node instead
      } else {
        node * &link = child_link(ptr->parent, key);
        link = (ptr->left == NULL) ? ptr->right : ptr->left;
        if (link != NULL) link->parent = ptr->parent;
      }
      delete ptr;
      mSize--;
      return 1;
    }

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
};

}

#endif

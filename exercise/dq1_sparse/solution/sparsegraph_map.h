#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        n = 3;
    }

    SparseGraph(int n_in) {
          n = n_in;
        // Your code here
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        n = G.n;
        s = G.s;
    }

    SparseGraph& operator=(const SparseGraph& G) {
        // Your code here
        n = G.n;
        s = G.s;
        return *this;
    }



    void AddEdge(int a, int b) {
        // Your code here
        s.insert(make_pair(a,b));
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        s.erase(make_pair(a,b));
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return (s.find(make_pair(a,b)) != s.end());
    }

    SparseGraph Transpose() const {
        SparseGraph GT(n);
        // Your code here
        for (auto &e : s) {
          GT.AddEdge(e.second,e.first);
        }
        return GT;
    }
protected:
    int n;
    // Your code here
    set<pair<int,int> > s;
};
#endif // __SPARSE_GRAPH_H__


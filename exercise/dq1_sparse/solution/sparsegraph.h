#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <algorithm>

using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        n = 3;
        g.resize(n);
    }

    SparseGraph(int n_in) {
          n = n_in;
        // Your code here
        g.resize(n);
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        n = G.n;
        g.resize(n);
        for (size_t i = 0; i < n; i++) g[i] = G.g[i];

    }

    SparseGraph& operator=(const SparseGraph& G) {
        // Your code here
        n = G.n;
        g.resize(n);
        for (size_t i = 0; i < n; i++) g[i] = G.g[i];
        return *this;
    }



    void AddEdge(int a, int b) {
        // Your code here
        if (find(g[a].begin(),g[a].end(),b) == g[a].end()) {
            g[a].push_back(b);
        }
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        vector<int>::iterator it = find(g[a].begin(),g[a].end(),b);
        if (it != g[a].end()) {
            g[a].erase(it);
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return (find(g[a].begin(),g[a].end(),b) != g[a].end());
    }

    SparseGraph Transpose() const {
        SparseGraph GT(n);
        // Your code here
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                GT.g[g[i][j]].push_back(i);
            }
        }
        return GT;
    }
protected:
    int n;
    // Your code here
    vector<vector<int> > g;
};
#endif // __SPARSE_GRAPH_H__


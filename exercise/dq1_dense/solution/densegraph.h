#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        n = 3;
        g.resize(n);
        for (int i =0; i < n; i++) {
            g[i].resize(n,0);
        }
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        g.resize(n);
        for (int i =0; i < n; i++) {
            g[i].resize(n,0);
        }
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        n = G.n;
        g.resize(n);
        for (int i =0; i < n; i++) {
            g[i] = G.g[i];
        }
    }

    DenseGraph& operator=(const DenseGraph& G) {
        // Your code here
        n = G.n;
        g.resize(n);
        for (int i =0; i < n; i++) {
            g[i] = G.g[i];
        }
        return *this;
    }

    void AddEdge(int a, int b) {
        // Your code here
        g[a][b] = 1;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        g[a][b] = 0;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return g[a][b] > 0;
    }

    DenseGraph Transpose() const {
        DenseGraph GT(n);
        // Your code here
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                GT.g[i][j] = g[j][i];
            }
        }
        return GT;
    }

protected:
    int n;
    // Your code here

    vector<vector<int> > g;
};

#endif // __DENSE_GRAPH_H__

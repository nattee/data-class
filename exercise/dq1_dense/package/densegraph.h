#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
    }

    DenseGraph(int n_in) {
        // Your code here
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
    }

    void AddEdge(int a, int b) {
        // Your code here
    }

    void RemoveEdge(int a, int b) {
        // Your code here
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
    }

    DenseGraph Transpose() const {
        // Your code here
    }

protected:
    int n;
    // Your code here
};
#endif // __DENSE_GRAPH_H__

#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here

using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
    }

    SparseGraph(int n_in) {
        // Your code here
    }

    SparseGraph(const SparseGraph& G) {
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

    SparseGraph Transpose() const {
        // Your code here
    }

protected:
    // Your code here
};
#endif // __SPARSE_GRAPH_H__


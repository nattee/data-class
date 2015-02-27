#include "sparsegraph.h"
#include <iostream>
#include <vector>
using namespace std;
bool runCase(int testCase) {
    if (testCase == 1) {
        SparseGraph g;
        g.AddEdge(0,1);
        if (!g.DoesEdgeExist(0,1)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
    } else
    if (testCase == 2) {
        SparseGraph g(400);
        g.AddEdge(0,1);
        g.AddEdge(0,2);
        g.AddEdge(1,2);
        g.AddEdge(1,3);
        if (!g.DoesEdgeExist(0,1)) return false;
        if (!g.DoesEdgeExist(0,2)) return false;
        if (!g.DoesEdgeExist(1,2)) return false;
        if (!g.DoesEdgeExist(1,3)) return false;
        if (g.DoesEdgeExist(0,3)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
    } else
    if (testCase == 3) {
        SparseGraph g2(40000);
        SparseGraph g(g2);
        g.AddEdge(0,1);
        g.AddEdge(0,2);
        g.AddEdge(1,2);
        g.AddEdge(1,3);
        if (!g.DoesEdgeExist(0,1)) return false;
        if (!g.DoesEdgeExist(0,2)) return false;
        if (!g.DoesEdgeExist(1,2)) return false;
        if (!g.DoesEdgeExist(1,3)) return false;
        if (g.DoesEdgeExist(0,3)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
    } else
    if (testCase == 4) {
        SparseGraph g2(80000);
        SparseGraph g = g2;
        g.AddEdge(0,1);
        g.AddEdge(0,2);
        g.AddEdge(1,2);
        g.AddEdge(1,3);
        g.AddEdge(2,3);
        g.AddEdge(1,0);
        g.RemoveEdge(1,0);
        g.AddEdge(0,3);
        g.RemoveEdge(0,3);
        g.AddEdge(3,2);
        g.RemoveEdge(3,2);
        g.AddEdge(3,3);

        if (!g.DoesEdgeExist(0,1)) return false;
        if (!g.DoesEdgeExist(0,2)) return false;
        if (!g.DoesEdgeExist(1,2)) return false;
        if (!g.DoesEdgeExist(1,3)) return false;
        if (!g.DoesEdgeExist(2,3)) return false;
        if (!g.DoesEdgeExist(3,3)) return false;
        if (g.DoesEdgeExist(0,3)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
        if (g.DoesEdgeExist(3,2)) return false;


    } else
    if (testCase == 5) {
        SparseGraph g2(50000);
        SparseGraph g(2);
        g = g2;
        g.RemoveEdge(1,2);
        g.RemoveEdge(0,1);
        g.AddEdge(0,1);
        g.AddEdge(0,2);
        g.AddEdge(1,2);
        g.RemoveEdge(1,3);
        g.AddEdge(1,3);
        g.RemoveEdge(4,2);
        g.AddEdge(4,2);
        g.RemoveEdge(1,0);
        g.AddEdge(0,3);
        g.RemoveEdge(0,3);
        g.AddEdge(3,2);
        g.RemoveEdge(3,2);

        if (!g.DoesEdgeExist(0,1)) return false;
        if (!g.DoesEdgeExist(0,2)) return false;
        if (!g.DoesEdgeExist(1,2)) return false;
        if (!g.DoesEdgeExist(1,3)) return false;
        if (!g.DoesEdgeExist(4,2)) return false;
        if (g.DoesEdgeExist(0,3)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
        if (g.DoesEdgeExist(2,4)) return false;
    } else
    if (testCase == 6) {
        int n = 90000;
        int k = 10000;
        SparseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        SparseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        SparseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }

    } else
    if (testCase == 7) {
        int n = 95000;
        int k = 200000;
        SparseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        SparseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        SparseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }

    } else
    if (testCase == 8) {
        int n = 100000;
        int k = 500000;
        SparseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        SparseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        SparseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }

    } else
    if (testCase == 9) {
        int n = 99997;
        int k = 300000;
        SparseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
            gt.RemoveEdge(a,b);
        }
        SparseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (g.DoesEdgeExist(a,b)) return false;
        }
    } else
    if (testCase == 10) {
        int n = 99995;
        int k = 500000;
        SparseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        SparseGraph g = gt.Transpose();
        gt = g.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!gt.DoesEdgeExist(a,b)) return false;
        }
        SparseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }

    }
    return true;
}
int main() {
    int testCase;
    cin>>testCase;
    if (runCase(testCase)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}

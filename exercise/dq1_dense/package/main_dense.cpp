#include "densegraph.h"
#include <iostream>
using namespace std;
bool runCase(int testCase) {
    if (testCase == 1) {
        DenseGraph g;
        g.AddEdge(0,1);
        if (!g.DoesEdgeExist(0,1)) return false;
        if (g.DoesEdgeExist(1,0)) return false;
    } else
    if (testCase == 2) {
        DenseGraph g(4);
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
        DenseGraph g2(4);
        DenseGraph g(g2);
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
        DenseGraph g2(4);
        DenseGraph g = g2;
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
        DenseGraph g2(5);
        DenseGraph g(2);
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
        int n = 20;
        int k = 100;
        DenseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        DenseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        DenseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g.DoesEdgeExist(i,j)) {
                    if (!g2.DoesEdgeExist(j,i)) return false;
                } else {
                    if (g2.DoesEdgeExist(j,i)) return false;
                }
            }
        }


    } else
    if (testCase == 7) {
        int n = 121;
        int k = 1000;
        DenseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        DenseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        DenseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g.DoesEdgeExist(i,j)) {
                    if (!g2.DoesEdgeExist(j,i)) return false;
                } else {
                    if (g2.DoesEdgeExist(j,i)) return false;
                }
            }
        }
    } else
    if (testCase == 8) {
        int n = 1000;
        int k = 100000;
        DenseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        DenseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g.DoesEdgeExist(a,b)) return false;
        }
        DenseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g.DoesEdgeExist(i,j)) {
                    if (!g2.DoesEdgeExist(j,i)) return false;
                } else {
                    if (g2.DoesEdgeExist(j,i)) return false;
                }
            }
        }
    } else
    if (testCase == 9) {
        int n = 1000;
        int k = 100;
        DenseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
            gt.RemoveEdge(a,b);
        }
        DenseGraph g = gt;
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (g.DoesEdgeExist(a,b)) return false;
        }
    } else
    if (testCase == 10) {
        int n = 999;
        int k = 200000;
        DenseGraph gt(n);
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            gt.AddEdge(a,b);
        }
        DenseGraph g = gt.Transpose();
        gt = g.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!gt.DoesEdgeExist(a,b)) return false;
        }
        DenseGraph g2 = gt.Transpose();
        for (unsigned int i = 0; i < k; i++) {
            int a = (int)(((i+32131)^77811+311) % n);
            int b = (int)(((i+132131)^778117+3111*i*i+3132117) % n);
            if (!g2.DoesEdgeExist(b,a)) return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (gt.DoesEdgeExist(i,j)) {
                    if (!g2.DoesEdgeExist(j,i)) return false;
                } else {
                    if (g2.DoesEdgeExist(j,i)) return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int testCase;
    cin>>testCase;
    if (runCase(testCase)) {
        cout<<"YES!$@*"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}

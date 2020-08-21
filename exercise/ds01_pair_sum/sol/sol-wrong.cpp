#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <assert.h>
using namespace std;


int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int,int> data;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        data[val]++;
    }
    for (int k = 0; k < m; k++)
    {
        int val;
        cin >> val;
        bool found = false;
        for (auto &x : data) {
          int need = val - x.first;
          if (need == x.first) {
            if (x.second > 0) {
              found = true;
              break;
            }
          } else {
            if (data.find(need) != data.end()) {
              found = true;
              break;
            }
          }
        }
        if (found) 
          cout << "YES\n";
        else 
          cout << "NO\n";
    }

}



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#include "student.h"

int main() {
  vector<pair<int,int> > v;
  int n,a,b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }
  cout << eval_postfix(v) << endl;
}

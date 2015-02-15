#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n,m;
  std::cin >> n >> m;

  //read input
  vector<int> a,b;
  while (n--) {
    int tmp;
    std::cin >> tmp;
    a.push_back(tmp);
  }
  while (m--) {
    int tmp;
    std::cin >> tmp;
    b.push_back(tmp);
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int lasta = a[0]-1;
  for (size_t i = 0;i < a.size();i++) {
    if (lasta == a[i]) continue;
    //a[i] is something new, we check it if b has it
    if (find(b.begin(),b.end(),a[i]) != b.end()) {
      cout << a[i] << " ";
    }
    lasta = a[i];
  }
  cout << endl;
}

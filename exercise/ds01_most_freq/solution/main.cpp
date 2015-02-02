#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int N,max;
  string st;
  cin >> N;

  map<string,int> m;
  while (N--) {
    cin >> st;
    m[st]++;

    if (m[st] > max) max = m[st];
  }

  map<string,int>::iterator it = m.end();
  while (it != m.begin()) {
    it--;
    if (it->second == max) {
      cout << it->first << " " << it->second << endl;
      break;
    }
  }
}

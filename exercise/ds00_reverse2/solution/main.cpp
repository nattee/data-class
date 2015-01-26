#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
  //write your code only in this function
  vector<int>::iterator it1,it2;
  it1 = a;
  it2 = b-1;
  while (it1 != it2) {
    int tmp;
    tmp = *it1;
    *it1 = *it2;
    *it2 = tmp;
    it1++;
    if (it1 == it2) break;
    it2--;
  }
}

int main() {
  //read input
  int n,a,b;
  cin >> n;
  vector<int> v;
  for (int i = 0;i < n;i++) {
    int c;
    cin >> c;
    v.push_back(c);
  }
  cin >> a >> b;

  //call function
  reverse(v,v.begin()+a,v.begin()+b+1);

  //display content of the vector
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << endl;
}

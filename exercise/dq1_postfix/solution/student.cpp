int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  stack<int> s;
  for (auto &x : v) {
    if (x.first == 1) {
      s.push(x.second);
    } else {
      int a,b;
      if (s.empty()) {
        cout << "ERROR" << endl;
        exit(0);
      }
      b = s.top(); s.pop();
      if (s.empty()) {
        cout << "ERROR" << endl;
        exit(0);
      }
      a = s.top(); s.pop();
      if (x.second == 0) s.push(a+b);
      else if (x.second == 1) s.push(a-b);
      else if (x.second == 2) s.push(a*b);
      else if (x.second == 3) s.push(a/b);
    }
  }
  if (s.size() != 1) {
    cout << "END ERROR" << endl;
    exit(0);
  }
  //DON"T FORGET TO RETURN THE RESULT
  return s.top();
}


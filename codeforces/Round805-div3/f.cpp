#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.push(x);
  }
  while (!a.empty()) {
    int t1 = a.top(), t2 = b.top();
    if (t1 == t2) {
      a.pop();
      b.pop();
    } else if (t1 > t2) {
      if (t1 & 1) {
        cout << "No" << endl;
        return;
      }
      a.pop();
      a.push(t1 / 2);
    } else {
      b.pop();
      b.push(t2 / 2);
    }
  }
  cout << "Yes" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int M;
  cin >> M;
  while (M--) {
    solve();
  }
  return 0;

}

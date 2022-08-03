#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int hh[11], mm[11];
int h, m;
vector<int> c;

void solve() {
  int n;
  cin >> n;
  c.clear();
  c.resize(n+1, 0);
  int index = 0;
  for (int i = 1; i <= n; ++i) {
     int x;
     cin >> x;
     if (!c[x]) {
      c[x] = i;
     } else {
       index = max(index, c[x]);
       c[x] = i;
     }
  }
  cout << index << endl;
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

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 +10;
map<int , vector<int>> m;
vector<int> c;
vector<int> d;
int n;
bool flag = true;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M;
  cin >> n >> M;
  c.resize(n+1, 0);
  d.resize(n+1, 0);
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    m[x].push_back(y);
    m[y].push_back(x);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    c[i] = 1;
    for (auto u : m[i]) {
      if (c[u]) {
        continue;
      }
      for (auto j : m[u]) {
        if (j == u || j == i) continue;
        if (count(m[j].begin(), m[j].end(), i)) {
          res ++;
        }
      }
    }
  }
  cout << res / 3 << endl;
  return 0;
}
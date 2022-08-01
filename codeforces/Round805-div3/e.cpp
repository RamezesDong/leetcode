#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int N = 2e5 +10;
map<int , vector<int>> m;
vector<int> color;
int n;
bool flag = true;

bool dfs(int v) {
  for (auto u: m[v]) {
    if(!color[u]){  //染色法
      color[u] = 3 - color[v];
      if (!dfs(u)) {
        return false;
      }
    } else if (color[u] == color[v]) {
      return false;
    }
  }
  return true;
}

void solve() {
  flag = true;
  for (int i = 1; i <= n ; ++i) {
    if (!color[i]) {
      color[i] = 1;
      if (!dfs(i)) {
        flag = false;
        //cout << "i is " << i;
        break;
      }
    }
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int K;
  cin >> K;
  while (K--) {
    m.clear();
    color.clear();
    flag = true;
    cin >> n;
    color.resize(n+1, 0);
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      m[x].push_back(y);
      m[y].push_back(x);
      if (x == y || m[x].size() > 2 || m[y].size() > 2) {
        flag = false;
        continue;
      }
    }
    if (!flag) {
      cout << "No" << endl;
      continue;
    }
    solve();
  }
  return 0;
}
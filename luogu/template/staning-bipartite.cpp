#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5 +10;
map<int , vector<int>> m;
vector<int> color(N, 0);
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
  int M;
  cin >> n >> M;
  for (int i = 0; i < M; ++i) {
    int x , y;
    cin >> x>>y;
    if (x == y) {
      flag = false;
      continue;
    }
    if (count(m[x].begin(), m[x].end(), y)) {
      continue;
    }
    m[x].push_back(y);
    m[y].push_back(x);
  }
  if (!flag) {
    cout << "No" << endl;
    return 0;
  }
  solve();
  return 0;
}
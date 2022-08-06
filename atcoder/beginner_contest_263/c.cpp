#include <bits/stdc++.h>
using namespace std;
int f[11];
int n,m;
void dfs(vector<int> a, int k) {
  if(a.size() == n) {
    for (int i = 0; i < a.size(); ++i) {
      cout << a[i] << " ";
    }
    cout << '\n';
    return;
  }
  if (k > m) {
    return;
  }
  a.push_back(k);
  dfs(a, k + 1);
  a.pop_back();
  dfs(a, k + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<int> a;
  dfs(a, 1);
  return 0;
}
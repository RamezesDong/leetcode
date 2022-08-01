#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[105];
vector<bool> flag;
int n;
int res = 0;
void dfs(int k, int now, ll val, int pre) {
  if (now == k) {
    if (val % k == 0) {
      res = (res + 1) % 998244353;
      return;
    }
  }
  for (int i = pre + 1; i < n; ++i) {
    if(flag[i]) {
      continue;
    }
    flag[i] = true;
    dfs(k, now + 1, val + (ll)a[i], i);
    flag[i] = false;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  res = n;
  for (int i = 2; i <= n; ++i) {
    flag.resize(n+1, 0);
    dfs(i, 0, ll(0), -1);
  }
  cout << res << endl;
  return 0;
}
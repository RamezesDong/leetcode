#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int f[N];
long long sa[N];
int n, l, r;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> r;
  for (int i = 1; i <= n ; ++i) {
    cin >> f[i];
    sa[i] = sa[i-1] + f[i]*1ll;
  }

  
  for (int i = 1; i <= n; ++i) {

  }
  
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
vector<int> c;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n ;
  c.resize(n+1, 0);
  int ca = 0;
  int cb = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == c[i]) {
      ca ++;
    } else {
      if (c[c[i]] == i) {
        cb ++;
      }
    }
  }
  res = ca*(ca - 1)/2 + cb/2;
  cout << res << endl;
  return 0;
}
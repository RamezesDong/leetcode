#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,m;
int c[1000010];
int a[1000010];
int b[1000010];
inline int lowbit(int x) {return x & (-x);}
typedef long long ll;

void add(int x, int k) {
  int k1 = x*k;
  while (x <= n) {
    a[x] += k;
    b[x] += k1;
    x += lowbit(x);
  }
}

ll getsum(int *t, int x) {
  ll res = 0;
  while (x > 0) {
    res += t[x];
    x -= lowbit(x);
  }
  return res;
}

void add1(int l, int r, int v) {
  add(l, v), add(r + 1, -v);
}

ll getsum1(int l, int r) {
  return (1ll + r)*getsum(a, r) - 1ll*l*getsum(a, l-1) -
    (getsum(b, r) - getsum(b, l-1));
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n ; ++i) {
    cin >>c[i];
    add(i, c[i] - c[i-1]);
  }
  int op, x, y, z;
  for (int i = 0; i < m; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x>> y >> z;
      add1(x, y ,z);
    } else {
      cin >> x>> y;
      cout << getsum1(x, y) << endl;
    }
  }
  return 0;
}
#include <iostream>
#include <algorithm>
//#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
int a[N];
int n, m;
inline int lowbit(int k) {return k & -k;}

// add method: x from small to large
void add(int x, int k) {
  while (x <= n) {
    a[x] += k;
    x = x + lowbit(x);
  }
}

void add1(int l, int r, int v) {
  add(l, v), add(r+1, -v);
}

// query x from large to small
int getsum(int x) {
  int res = 0;
  while (x >= 1) {
    res += a[x];
    x = x - lowbit(x);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int b;
    cin >> b;
    add1(i, i, b);
  }
  int l,r,x;
  int op;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> l >> r >> x;
      add1(l, r, x);
    } else if (op == 2) {
      cin >> x;
      cout << getsum(x) << endl;
    }
  }
  return 0;
}
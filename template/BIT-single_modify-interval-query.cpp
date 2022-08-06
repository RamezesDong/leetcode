#include <iostream>
#include <algorithm>
//#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
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
/*  for (int i = 1; i <= n; ++i) {
   int b;
   cin >> b;
    add(i, b);
  }*/
  int x, y;
  char op;
  while (m--) {
    cin >> op>> x>> y;
    if (op == 'x') {
      add(x, y);
    } else  {
      cout << getsum(y) - getsum(x-1) << endl;
    }
  }
  return 0;
}
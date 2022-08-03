#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int hh[11], mm[11];
int h, m;
int mih, mim;
int comparehm(int h1, int m1) {
  if (h1 < mih) {
    return 1;
  } else if (h1 > mih) {
    return 0;
  } else {
    return m1 < mim;
  }
}

void solve() {
  int n;
  cin >> n >> h >> m;
  mih = INF, mim = INF;
  for (int i = 0; i < n; ++i) {
    int x,y;
    cin >> x >> y;
    int a = 0,b = 0;
    if (x > h) {
      a = x - h - 1;
      b = 60 - m + y;
      if (b >= 60) {
        a ++;
        b -= 60;
      }
    } else if (x < h) {
      a = 23 - h + x;
      b = 60 - m + y;
      if (b >= 60) {
        a++;
        b-=60;
      }
    } else {
      if (y < m) {
        a = 23;
        b = 60 - (m - y);

      } else {
        a = 0;
        b = y-m;
      }
    }
    if(comparehm(a, b)) {
      mih = a;
      mim = b;
    }
  }
  cout << mih << " " << mim<< endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int M;
  cin >> M;
  while (M--) {
    solve();
  }
  return 0;

}

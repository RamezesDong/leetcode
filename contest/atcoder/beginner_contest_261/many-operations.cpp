#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int t[N], a[N], res[30][N][2];
int n;

void solve(int x) {
  for (int i = 0; i < 30; ++i) {
    res[i][0][0] = 0;
    res[i][0][1] = 1;
  }
  for (int j = 1; j <= n; ++j) {
    //int bit = a[i] >> i & 1;
    for (int i = 0; i < 30; ++i) {
      for (int k = 0; k < 2; ++k) {
        int a1 = 0, b = 1;
        if(t[j-1]==1) {
          res[i][j][k] = res[i][j-1][k] & (a[j - 1] >> i & 1);
        } else if (t[j-1]==2) {
          res[i][j][k] = res[i][j-1][k] | (a[j - 1] >> i & 1);
        } else {
          res[i][j][k] = res[i][j-1][k] ^ (a[j - 1] >> i & 1);
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int r = 0;
    for (int j = 0; j < 30; ++j) {
      r += res[j][i][x >> j & 1] << j;
    }
    cout << r << endl;
    x = r;
  }
}
int main()
{
  int x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> a[i];
  }
  solve(x);
  return 0;
}
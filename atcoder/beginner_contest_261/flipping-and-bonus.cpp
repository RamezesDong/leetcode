#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int dp[5100][5100];
signed main() {
  int m,n;
  int x[5100];
  int c[5100];
  memset(c, 0 ,sizeof (c));
  cin >> n >>m;
  for(int i = 0; i < n ; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; ++i) {
    int ci, bo;
    cin >> ci >> bo;
    c[ci] = bo;
  }
  dp[0][0] = 0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x[i-1] + c[j]);
      if (j > i) {
        continue;
      }
      dp[i][0] = max(dp[i][0], dp[i - 1][j - 1]);
      //cout << "i, j is" << i << " "<< j << " , " <<dp[i][j]<<endl;
      //sum = max(sum, max(dp[i][j], dp[i][0]));
    }
  }
  for (int i = 0; i <= n; ++i) {
    sum = max(sum, dp[n][i]);
  }
  cout << sum << endl;
  return 0;
}
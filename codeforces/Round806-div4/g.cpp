#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
ll dp[N][32];
int main() {
  int k;
  cin >> k ;
  int n;
  int cost;
  while (k--)
  {
    cin >> n >> cost;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    for(int i = 1; i <= n; i ++ )
      for(int j = 0; j <= 31; j ++ )
        dp[i][j] = -1e18;
    ll res = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n ; ++i) {
      dp[i][0] = dp[i-1][0] + a[i]*1ll - cost*1ll;
      //res = max(dp[i][0], res);
      for (int j = 1; j <= 31; ++j) {
        dp[i][j] = max(dp[i][j], max(dp[i-1][j-1] + (ll)(a[i]>>j), dp[i-1][j] + (a[i]>>j)*1ll - cost*1ll));
        //res = max(res,dp[i][j]);
      }
      dp[i][31] = max(dp[i][31], dp[i - 1][31]);
    }
    for (int i = 0; i <= 31; ++i) {
      res = max(res, dp[n][i]);
    }
    cout << res << endl;
    //memset(dp, 0, sizeof(dp)*sizeof(dp[0]));
  }
  return 0;
}
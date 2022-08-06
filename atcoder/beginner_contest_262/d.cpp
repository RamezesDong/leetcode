#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[105];
vector<bool> flag;
int n;
int res = 0;
const int Mod = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(i+1, vector<int>(i, 0)));
    dp[0][0][0] = 1;
    for (int j = 0; j <n ; ++j) {
      for (int k = 0; k <= i; ++k) {
        for (int l = 0; l < i; ++l) {
          dp[j+1][k][l] = (dp[j+1][k][l] + dp[j][k][l])%Mod ;
          if (k!=i) dp[j+1][k+1][(l + a[j])%i] = (dp[j+1][k+1][(l + a[j])%i] + dp[j][k][l])%Mod;
        }
      }
    }
    res = (res + dp[n][i][0]) % Mod;
  }

  cout << res << endl;

  return 0;
}
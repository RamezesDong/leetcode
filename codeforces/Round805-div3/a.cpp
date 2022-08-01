#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll dp[N][32];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k ;
  int a;
  while (k--) {
    cin >> a;
    int b = a;
    int count = -1;
    while (b > 0) {
      b = b/10;
      count ++;
    }
    cout << a - (int)pow(10, count) << endl;
  }
  return 0;
}
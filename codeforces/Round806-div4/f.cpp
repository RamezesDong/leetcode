#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];
int main() {
  int k;
  cin >> k ;
  int n;
  while (k--)
  {
    cin >> n;
    unordered_set<string> set;
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }
    ll res = 0;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      if(a[i] >= i) continue;
      res += (ll)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
      v.push_back(i);
    }
    cout << res << endl;
  }
  return 0;
}
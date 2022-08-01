#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
char s[3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> m;
  while (m--) {
    string a;
    cin >> a;
    int res = 0;
    int flag = 0;
    for (int i = 0; i < a.length(); ++i) {
      if (flag == 0) {
        s[0] = a[i];
        flag ++;
      } else if (flag == 1) {
        if (s[0] == a[i]) {
          continue;
        }
        s[1] = a[i];
        flag ++;
      } else if (flag == 2) {
        if (s[0] == a[i] || s[1] == a[i]) {
          continue;
        }
        s[2] = a[i];
        flag ++;
      } else {
        if (s[0]==a[i] || s[1] == a[i] || s[2] == a[i]) {
          continue;
        }
        flag = 1;
        res ++;
        s[0] = a[i];
      }
    }
    cout << res +1 <<endl;
  }
  return 0;
}
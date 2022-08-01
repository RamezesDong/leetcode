#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
#define a first
#define b second
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> m;
  while (m--) {
    int n, q;
    cin >> n >> q;
    vector<int> num(n+1);
    unordered_map<int, pair<int, int>> map;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (!map.count(num[i])) {
        map[num[i]].a = i;
        map[num[i]].b = i;
      } else {
        map[num[i]].b = i;
      }
    }

    for (int i = 0; i < q; ++i) {
      int x, y;
      cin >>x >> y;
      if (!map.count(x) || !map.count(y) || map[x].a > map[y].b) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
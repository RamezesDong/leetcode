#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int fa[N], ranks[N];
// add merging by rank
inline void init(int n) {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    ranks[i] = 1;
  }
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  } else {
    // path compression
    fa[x] = find(fa[x]);
    return fa[x];
  }
}

inline void merge(int a, int b) {
  int x = find(a), y = find(b);
  if (ranks[x] <= ranks[y]) {
    fa[x] = y;
  } else fa[y] = x;
  if (ranks[x] == ranks[y] && x!=y) {
    ranks[y] ++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n,m,p;
  cin >> n >> m >> p;
  init(n);
  for (int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    merge(a, b);
  }
  for (int i = 0; i < p; ++i) {
    int a, b;
    cin >> a >> b;
    if (find(a) == find(b)) {
      cout << "Yes" << endl;
    } else cout << "No" <<endl;
  }
  return 0;
}
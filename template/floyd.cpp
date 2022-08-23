#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
int dist[400][400];
void floyd(int n) {
    for (int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dist, 0x3f3f3f3f, sizeof(dist));
  int n, k , m;
  cin >> n >> k >> m;
  for(int i = 1; i <= n; ++i) {
      dist[i][i] = 0;
  }
  for(int i = 0; i < k; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      dist[u][v] = min(dist[u][v], w);
  }
  floyd(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if(dist[u][v] > 2000000) {
      cout << "impossible"<<endl;
    } else {
      cout << dist[u][v]<<endl;
    }
  }
  return 0;
}
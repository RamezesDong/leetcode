#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
// 堆优化Dijkstra 复杂度从O(N)降到 O(mlogm)
int dist[400];
queue<int> Q;
struct Polar{
    int dist, id;
    Polar(int dist, int id) : dist(dist), id(id);
};

struct cmp{
    bool operator ()(Polar a, Polar b) {
      return a.dist < b.dist;
    }
};
void Dij(int s) {
  dist[s] = 0;
  Q.push(Polar(0,s));
  while (!Q.empty()) {
    int p = Q.top().id;
    Q.pop();
    if(vis[p]) continue;
    vis[p] = 1;
    for (int e = head[p]; e != 0 ; e = edges[e].next) {
      
    }
  }
}
int main() {

}
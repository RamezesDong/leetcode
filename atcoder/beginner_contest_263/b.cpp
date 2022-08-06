#include <bits/stdc++.h>
using namespace std;
int fa[51];
int n;
void init() {
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
}

void merge(int fat, int ch) {
  fa[ch] = fat;
}

int find(int x) {
  if (x == fa[x]) {
    return fa[x];
  } else return find(fa[x]);
}

int countG(int x) {
  if (x == fa[x]) {
    return 0;
  } else
    return 1 + countG(fa[x]);
}

int main() {
  cin >> n;
  init();
  int gen = 1;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    merge(x, i);
  }
  cout << countG(n) <<endl;
  return 0;
}
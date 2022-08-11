#include <bits/stdc++.h>
using namespace std;
namespace trie {
    const int MAXN = 500005;
    int next[MAXN][26], cnt;
    bool vis[MAXN], exist[MAXN];

// vis 记录是否访问过， exist[] indicates whether a string contains
    void init() {
      memset(next, 0, sizeof(next));
      cnt = 1;
    }

// cnt 值对应边
    void insert(const string &s) {
      int cur = 1;
      for (auto c: s) {
        // 路径为空则新建节点
        if (!next[cur][c - 'a'])
          next[cur][c - 'a'] = ++cnt;
        cur = next[cur][c - 'a'];
      }
      exist[cur] = true;
    }

    bool find_prefix(const string &s) {
      int cur = 1;
      for (auto c: s) {
        if (!next[cur][c - 'a']) {
          return false;
        }
        cur = next[cur][c - 'a'];
      }
      return true;
    }

     int find(const string &s) {
      int cur = 1, ans;
      for (auto c: s) {
        if (!next[cur][c - 'a']) {
          return 0;
        }
        cur = next[cur][c - 'a'];
      }
      if (!exist[cur]) {
        return 0;
      } else if (!vis[cur]) {
        //cout << "cur" << cur << endl;
        ans = 1;
      } else {
        //cout << "cur has vis " << cur << endl;
        ans = 2;
      }
      vis[cur] = true;
      return ans;
    }
}
int main() {
  trie::init();
  int n,m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    trie::insert(s);
  }
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    switch (trie::find(s)) {
      case 0:
        cout<< "WRONG" << '\n';
        break;
      case 1:
        cout << "OK" << '\n';
        break;
      case 2:
        cout << "REPEAT" << "\n";
    }
  }
  return 0;
}
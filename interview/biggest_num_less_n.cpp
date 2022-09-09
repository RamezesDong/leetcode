/*
 * 经典字节面试题:
 * 给定一个数 n,如 23121,给定一组数 A,{2, 4, 9},返回用A可以组成的小于 n 的 最大数（22999）
 * 与 leetcode 902 类似
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 10010;
vector<int> a, v;
int n, ans, target;
bool flag;
void dfs(int pos, int cur, int use, bool limit) {
  if (pos == v.size()) {
    //cout << cur << endl;
    if (cur < target && cur != 0) {
      ans = max(cur, ans);
    }
    return;
  }

  if (!use) {
    dfs(pos + 1, 0, use, false);
  }

  for (int i = 0; i < n; ++i) {
    if (limit) {
      if (a[i] > v[pos]) {
        continue;
      } else if (a[i] == v[pos]) {
        dfs(pos + 1, cur*10 + a[i], 1, true);
      } else {
        dfs(pos + 1, cur*10 + a[i], 1, false);
      }
    } else {
      dfs(pos + 1, cur*10 + a[i], 1, false);
    }
  }
}

void caseTest(vector<int> tmp, int x) {
  target = x;
  ans = -1;
  flag = false;
  // 将 最大数 每一位存入
  v.clear();
  int px = x;
  while (x > 0) {
    v.push_back(x%10);
    x = x / 10;
  }
  reverse(v.begin(), v.end());

  // tmp.insert(tmp.begin(), 0);
  n = tmp.size();
  a = tmp;
  dfs(0, 0, 0, true);
  cout << "x is " << px << ", ans is " << ans << endl;
}

int main() {
  caseTest({1, 2, 4, 9}, 2533); // 2499
  caseTest({ 1, 2, 4, 9 }, 2409); // 2299
  caseTest({ 1, 2, 4, 9 }, 1111); // 999
  caseTest({ 1, 2, 4, 9 }, 3000); // 2999
  caseTest({ 1, 2, 4, 9 }, 2100); // 1999
  caseTest({ 1, 2, 4, 9 }, 1249); // 1244
  caseTest({ 1, 2, 4, 9 }, 4921); // 4919
  caseTest({ 1, 2, 4, 9 }, 1); // -1
  caseTest({ 1, 2, 3 }, 101);
  caseTest({ 1, 2, 9 }, 1201); // 1121
  caseTest({ 1, 4, 9 }, 24132);
  caseTest({ 1, 4, 9 }, 14132);
  caseTest({ 2, 4, 5 }, 24131);
  caseTest({ 2, 4, 9 }, 23132); // 22999
  caseTest({ 2, 4, 9 }, 21132); // 9999
  caseTest({ 2, 4, 9 }, 24132); // 19999
  caseTest({ 2, 4, 9 }, 14132); // 14119
  caseTest({ 2, 3, 5 }, 3211);
  caseTest({ 6, 7, 8 }, 1200);
  caseTest({ 6, 9 }, 95); // 69
  return 0;
}
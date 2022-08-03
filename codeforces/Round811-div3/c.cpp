#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int hh[11], mm[11];
int h, m;
vector<int> c;
int ans[46] = {0, 1, 2, 3 , 4, 5, 6, 7, 8, 9, 19,
               29, 39, 49, 59,69,69,89,189, 289, 389,
              489, 589, 689, 789, 1789, 2789, 3789, 4789, 5789, 6789,
              16789, 26789,36789,46789,56789, 156789,256789,356789,456789,
              1456789,2456789,3456789, 13456789,23456789, 123456789};
void solve() {
  int n;
  cin >> n;
  int k = 9;
  string s = "";
  if (n <= k) {
    s = (char)('0' + n) + s;
  } else {
    for (int i = k; i >= 1 ; --i) {
      if (n - i > 0) {
        s = (char)('0' + i) + s;
        n = n - i;
      } else {
        s = (char)('0' + n) + s;
        break;
      }
    }
  }
  cout << s << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int M;
  cin >> M;
  while (M--) {
    solve();
  }
  return 0;

}

#include <bits/stdc++.h>
using namespace std;

int s2 = 0, s3 = 0;
bool ans = true;
set<int> s1;


void state2(int d) {
  if (d % 10 == 2 || d % 10 == 4 || d % 10 == 8) {
    if ((d/10)%2 == 1) {
      s2 ++;
    } else {
      s3 ++;
    }
  }
}
void solve() {
  int n;
  cin >> n;
  s1.clear();
  s2 =s3 = 0;
  ans = true;
  int d;
  for (int i = 0; i < n; ++i) {
    cin >> d;
    if (d & 1) {
      d += d %10;
    }
    if (d %10 == 0) {
      s1.insert(d);
    } else if (d % 10 == 6) {
      d += 6;
      state2(d);
    } else {
      state2(d);
    }
  }
  if (s1.size()) {
    if (s1.size() == 1 && s2 + s3 == 0) {
      cout << "Yes" <<endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    if (s2 == n || s3 ==n) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}



int main() {
  int K;
  cin >> K;
  while (K--) {
    solve();
  }
  return 0;
}
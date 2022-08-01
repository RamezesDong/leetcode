#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  if (k % 4 == 2) {
    cout << k << endl;
  } else {
    int d = k / 4;
    if (k% 4 > 2)
    cout << (d+1)*4 + 2 << endl;
    else cout<< d * 4 + 2 <<endl;
  }
  return 0;

}

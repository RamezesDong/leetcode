#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[5];
  int ca=0, cb=0;
  unordered_map<int,int> m;

  for (int i = 0; i < 5; ++i) {
    cin >> a[i];
  }
  sort(a, a+5);
  if ((a[0]==a[2]&&a[2]!=a[3]&&a[3]==a[4]) || (a[0]==a[1]&&a[1]!=a[2]&&a[2]==a[4])){
    cout << "Yes" << endl;
  } else cout << "No" << endl;
  return 0;
}
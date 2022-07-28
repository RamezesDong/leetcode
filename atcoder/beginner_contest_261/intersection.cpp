#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int a, b, c, d;
  cin >> a>> b >> c >>d;
  if(a >= d || b <= c) {
    cout << 0;
    return 0;
  }
  cout << min(b , d) - max(a, c);
  return 0;
}
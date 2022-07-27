#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
const int N = 1e6+10;
int n,k;
int a[N];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  deque<int> de;
  for (int i = 0; i < n; ++i) {
    while (!de.empty() && de.back() > a[i]) de.pop_back();
    de.push_back(a[i]);
    if (i - k >= 0 && de.front() == a[i-k]) {
      de.pop_front();
    }
    if (i >= k -1) {
      printf("%d ", de.front());
    }
  }
  de.clear();
  printf("\n");
  for (int i = 0; i < n; ++i) {
    while (!de.empty() && de.back() < a[i]) de.pop_back();
    de.push_back(a[i]);
    if (i - k >= 0 && de.front() == a[i - k]) {
      de.pop_front();
    }
    if (i >= k -1) {
      printf("%d ", de.front());
    }
  }
  return 0;
}
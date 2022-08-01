#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <cmath>
#include <utility>
#define a first
#define b second
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> m;
  while (m--) {
    string s;
    int k;
    vector<int> count(26, 0);
    cin >> s >> k;
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
      count[s[i] - 'a'] ++;
      sum += s[i] - 'a' + 1;
    }
    int now = 25;
    while (sum > k) {
      while (now >= 0 && count[now] == 0) {
        now --;
      }
      sum -= now + 1;
      count[now]--;
    }
    string res = "";
    for (int i = 0; i < s.length(); i++) {
      if (count[s[i] - 'a'] > 0) {
        res += s[i];
        count[s[i]-'a']--;
      }
    }
    cout <<res <<endl;
  }
  return 0;
}
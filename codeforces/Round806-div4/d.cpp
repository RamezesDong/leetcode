#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
string sa[N];
int res[N];
int main() {
    int k;
    cin >> k ;
    int n;
    while (k--)
    {
        cin >> n;
        unordered_set<string> set;
        for (int i = 0; i < n; i++)
        {
            cin >> sa[i];
            set.insert(sa[i]);
        }
        for (size_t i = 0; i < n; i++)
        {
          res[i] = 0;
          for (int j = 1; j <sa[i].length()  ; ++j) {
            string s1 = sa[i].substr(0, j), s2 = sa[i].substr(j, sa[i].length() - j);
            if (set.find(s1) != set.end() && set.find(s2) != set.end()) {
              res[i] = 1;
              break;
            }
          }
        }
        for (size_t i = 0; i < n; i++)
        {
            printf("%d", res[i]);
        }
        printf("\n");
        set.clear();
        //memset(ha, 0, sizeof(ha));
    }
    return 0;
}
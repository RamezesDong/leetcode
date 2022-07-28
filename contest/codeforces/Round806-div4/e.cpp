#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <cstdio>
using namespace std;
const int N = 1e3 + 10;
char a[N][N];
int main() {
    int k;
    cin >> k ;
    int n;
    while (k--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i]);
            /* code */
        }
        int sum = 0;
        for (int i = 0; i < (n+1)/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                if(i == 0 && j == n-1) continue;
                int count = a[i][j] + a[n-i-1][n-j-1] + a[n-j-1][i] + a[j][n-i-1] - 4*'0' ;
                //cout << "i = " <<i << "j = " << j << " count = "<< count << endl;
                if(count == 4 || count == 0) {
                    sum += 0;
                } else if(count == 1 || count == 3) {
                    sum += 1;
                } else {
                    sum += 2;
                }
            }
            /* code */
        }
        cout << sum << endl;
        //memset(ha, 0, sizeof(ha));
    }
    return 0;
}
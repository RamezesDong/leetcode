#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int ha[26];
int main() {
    int k;
    cin >> k ;
    int n;
    while (k--)
    {
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(ha[s[i] - 'A'] == 0) {
                sum += 2;
                ha[s[i] - 'A'] = 1;
            } else {
                sum += 1;
            } 
        }
        cout << sum <<endl;
        memset(ha, 0, sizeof(ha));
    }
    return 0;
}
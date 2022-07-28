#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int ha[105];
int main() {
    int k;
    cin >> k ;
    int n;
    while (k--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ha[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            //bool flag = true;
            int count = 0;
            int b;
            string s;
            cin >> b >> s;
            for (int j = 0; j < b; j++)
            {
                if(s[j] == 'U') count ++;
                else count --;
            }
            if (count > 0)
            {
                ha[i] = (ha[i] + 10 - count) % 10; 
            } else if(count < 0) {
                ha[i] = (ha[i] - count) % 10;
            } else {
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ha[i] << " ";
        }
        cout << endl;
        //memset(ha, 0, sizeof(ha));
    }
    return 0;
}
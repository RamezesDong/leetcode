#include<iostream>
using namespace std;
int main() {
    int n, l , r;
    cin >> n;
    if (n == 1) {
        cout << "1/1"<<endl;
        return 0;
    }
    int k = 1;
    int sum = 1;
    int flag = -1;
    while (sum < n) {
        k++;
        sum += k;
        flag = -flag;
        // cout << k << endl;
    }
    sum = sum - k;
    k = k - 1;
    if (flag == 1) {
        l = 1;
        r = k + 1;
    } else {
        l = k + 1;
        r = 1;
    }
    int d = n - sum - 1;
    flag = -flag;
    while (d > 0)
    {
        r = r + flag;
        l = l - flag;
        d--;
    }
    cout << l << "/" << r <<endl;
    return 0;
}
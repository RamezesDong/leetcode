#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if(s.length() != 3) {
            cout << "NO" <<endl;
            continue;
        }
        if (s[0]!='Y'&& s[0]!='y') {
            cout << "NO" <<endl;
            continue;
        }
        if (s[1]!='e'&& s[1]!='E')
        {
            cout << "NO" <<endl;
            continue;
        }
        if (s[2] != 's' && s[2] != 'S')
        {
            cout<< "NO" <<endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
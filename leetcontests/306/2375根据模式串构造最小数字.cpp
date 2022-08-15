class Solution {
public:
    string smallestNumber(string pattern) {
        char cur = '1';
        int n = pattern.length();
        string res(n+1, 0);
        int i = 0;
        while(i < n) {
            if(i && pattern[i] == 'I') i++;
            for(; i < n && pattern[i] == 'I'; ++i) res[i] = cur++;
            int i0 = i;
            while(i < n && pattern[i] == 'D') ++i;
            cout << "i0 i" << i0 << " " << i << endl;
            for(int j = i; j >= i0; j --) 
            {
                res[j] = cur++;
            }
        }
        return res;
    }
};
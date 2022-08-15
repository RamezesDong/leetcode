class Solution {
public:
    int dp[10][1 << 10][2];
    int a[10], cnt;
    int countSpecialNumbers(int n) {
        cnt = 0;
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        while(n) {
            a[cnt++] = n%10;
            n /= 10;
        }
        reverse(a, a + cnt);
        return dfs(0, 0, true);
    }

    int dfs(int pos, int mask, bool limit) {
        int ans = 0;
        if (pos == cnt) {
            return mask > 0;
        }
        if(dp[pos][mask][limit] != -1) {
            return dp[pos][mask][limit];
        }
        if(mask == 0) {
            ans += dfs(pos + 1, mask, false);
        }
        for(int i = (mask == 0); i <= (limit? a[pos]:9);++i) {
            if ((mask >> i)&1) {
                //cout <<"pos "<<pos << " skip " << i <<endl;
                continue;
            }
            // cout <<"pos is " << pos <<  " ans is " << ans << "\n";
            ans += dfs(pos + 1, mask|(1 << i), limit && i == a[pos]);
            // cout <<"after pos is " << pos <<  " ans is " << ans << "\n";
        }
        //cout << endl;
        dp[pos][mask][limit] = ans;
        return ans;
    }
};
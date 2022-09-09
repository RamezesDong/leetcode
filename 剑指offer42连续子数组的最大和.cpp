class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int dp[len+1];
        dp[0] = 0;
        int res = nums[0];
        for(int i = 1;i <= nums.size(); i++) {
            if(dp[i-1] < 0) {
                dp[i] = nums[i-1];
            } else {
                dp[i] = dp[i-1] + nums[i-1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
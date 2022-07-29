/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Bit{
private:
    vector<int> a;
    int size;
public:
    Bit(int n):size(n), a(n+1) {
    }

        int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int k) {
        while(x <= size) {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while(x >= 1) {
            res += a[x];
            x -= lowbit(x);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> tmp = nums;
        if (n < 2) {
            return res;
        }
        sort(tmp.begin(), tmp.end());
        for (int& num : nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        }
        Bit bit(n);
        for(int i = n-1; i >= 0; i --) {
            res[i] = bit.query(nums[i] - 1);
            bit.add(nums[i],1);
        }
        return res;
    }
};

// @lc code=end


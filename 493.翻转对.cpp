/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Bit
{
private:
    vector<int> a;
    int size;
public:
    Bit(int n):a(n+1),size(n) {
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int x, int k) {
        while (x <= size)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int res = 0;
        while (x >= 1)
        {
            res += a[x];
            x -= lowbit(x);
        }
        return res;
    }
};


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<long long> tmp;
        for (int x :nums)
        {
            tmp.insert(x);
            tmp.insert((long long)(x*1ll * 2));
        }
        unordered_map<long long, int> map;
        int idx = 0;
        for (long long x : tmp)
        {
            map[x] = ++idx;
        }
        int res = 0;
        Bit bit(map.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int left = map[(long long)nums[i] * 2], right = map.size();
            res += bit.query(right) - bit.query(left);
            bit.update(map[nums[i]], 1);
        }
        return res;
        
    }
};
// @lc code=end


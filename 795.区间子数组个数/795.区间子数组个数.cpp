/*
 * @Descroption: LeetCode 795. 区间子数组个数
 * @Author: EmoryHuang
 * @Date: 2021-08-15 12:27:18
 * @Method:
 * 动态规划
 * 使用count计算数组中小于等于x的子数组的数量
 * 最后的结果即为count(right) - count(left - 1)
 */

class Solution {
   public:
    int count(vector<int> nums, int x) {
        int ans = 0, cur = 0;
        for (auto num : nums) {
            cur = num <= x ? cur + 1 : 0;
            ans += cur;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) { 
        return count(nums, right) - count(nums, left - 1); 
    }
};
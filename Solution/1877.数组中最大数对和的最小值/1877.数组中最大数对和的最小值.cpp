/*
 * @Descroption: LeetCode 1877. 数组中最大数对和的最小值
 * @Author: EmoryHuang
 * @Date: 2021-07-20 19:16:20
 * @解题思路:
 * 排序 + 遍历
 * 因为题目要求最大数对和最小，那么就可以先排序，然后首尾元素组成数对
 * 最后取最大值
 */

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) ans = max(ans, nums[i] + nums[n - i - 1]);
        return ans;
    }
};
/*
 * @Descroption: LeetCode 1913. 两个数对之间的最大乘积差
 * @Author: EmoryHuang
 * @Date: 2021-09-23 19:10:40
 * @Method:
 * 简单题，排序之后取头尾4个元素
 */

class Solution {
   public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
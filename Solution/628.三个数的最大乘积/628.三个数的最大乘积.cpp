/*
 * @Descroption: LeetCode 628. 三个数的最大乘积
 * @Author: EmoryHuang
 * @Date: 2021-04-28 15:20:36
 * @解题思路:
 * 若排序后最大三个数都是正数，则这三个数的乘积就是结果；
 * 若存在负数，则可能是两个最小负数（即绝对值最大）与最大正数的乘积
 */

class Solution {
   public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
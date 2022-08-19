/*
 * @Descroption: LeetCode 1. 两数之和
 * @Author: EmoryHuang
 * @Date: 2021-03-15 19:20:36
 * @解题思路: 简单题，直接遍历所有元素，若两个元素之和相等，则返回下标
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
            for (int j = i + 1; j < len; j++)
                if (nums[i] + nums[j] == target) return {i, j};
        return {};
    }
};
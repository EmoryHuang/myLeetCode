/*
 * @Descroption: LeetCode 1608. 特殊数组的特征值
 * @Author: EmoryHuang
 * @Date: 2021-06-24 15:55:00
 * @解题思路:
 * 排序，然后寻找 x，满足前一个数小于 x 后一个数大于等于 x
 */

class Solution {
   public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] >= n) return n;
        for (int i = 1; i <= n; i++)
            if (nums[n - i] >= i && nums[n - i - 1] < i) return i;
        return -1;
    }
};
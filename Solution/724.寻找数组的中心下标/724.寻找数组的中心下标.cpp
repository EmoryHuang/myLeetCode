/*
 * @Descroption: LeetCode 724. 寻找数组的中心下标
 * @Author: EmoryHuang
 * @Date: 2021-06-16 14:34:00
 * @解题思路:
 * 简单题，遍历数组，若去除当前元素后前半部分和为数组元素的一半则返回下标
 */

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, cur = 0;
        for (int num : nums) sum += num;
        for (int i = 0; i < nums.size(); i++) {
            if (2 * cur + nums[i] == sum) return i;
            cur += nums[i];
        }
        return -1;
    }
};
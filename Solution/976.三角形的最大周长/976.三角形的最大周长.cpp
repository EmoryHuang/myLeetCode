/*
 * @Descroption: LeetCode 976. 三角形的最大周长
 * @Author: EmoryHuang
 * @Date: 2021-07-10 15:23:04
 * @解题思路:
 * 排序后从后往前遍历数组，若连续三个数能组成三角形，则为最大周长
 */

class Solution {
   public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 排序后从后往前遍历数组
        for (int i = nums.size() - 1; i >= 2; i--)
            // 若连续三个数能组成三角形
            if (nums[i] < nums[i - 1] + nums[i - 2]) 
                return nums[i] + nums[i - 1] + nums[i - 2];
        return 0;
    }
};
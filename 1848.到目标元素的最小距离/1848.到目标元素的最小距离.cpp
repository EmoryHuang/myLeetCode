/*
 * @Descroption: LeetCode 1848. 到目标元素的最小距离
 * @Author: EmoryHuang
 * @Date: 2021-06-16 15:29:00
 * @解题思路:
 * 简单题，遍历一遍数组，找到 target ，然后寻找最小距离
 */

class Solution {
   public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target) ans = min(ans, abs(i - start));
        return ans;
    }
};
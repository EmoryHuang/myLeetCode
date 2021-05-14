/*
 * @Descroption: LeetCode 485. 最大连续 1 的个数
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:52:36
 * @解题思路:
 * 简单题，遍历一遍并记录最大连续 1 的个数即可
 */

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int num : nums) {
            if (num == 1) {
                cnt++;
                ans = max(ans, cnt);
            } else
                cnt = 0;
        }
        return ans;
    }
};
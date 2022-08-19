/*
 * @Descroption: LeetCode 1512. 好数对的数目
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:15:36
 * @解题思路:
 * 暴力遍历
 */

class Solution {
   public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) ans++;
            }
        }
        return ans;
    }
};
/*
 * @Descroption: LeetCode 1480. 一维数组的动态和
 * @Author: EmoryHuang
 * @Date: 2021-05-07 19:50:36
 * @解题思路:
 * 简单题，遍历数组，把每次的累加放入数组
 */

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            ans.push_back(sum);
        }
        return ans;
    }
};
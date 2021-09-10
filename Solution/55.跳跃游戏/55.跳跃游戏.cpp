/*
 * @Descroption: LeetCode 55. 跳跃游戏
 * @Author: EmoryHuang
 * @Date: 2021-05-12 15:57:36
 * @解题思路: 遍历数组，每一步更新能够到达的最大值 `reach`，若 `i > reach` 则说明不能到达
 */

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);  // 每走一步更新能够到达的最大值
        }
        return true;
    }
};
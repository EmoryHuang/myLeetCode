/*
 * @Descroption: LeetCode 376. 摆动序列
 * @Author: EmoryHuang
 * @Date: 2021-04-23 15:35:36
 * @解题思路:
 * 分析题意之后，发现只需要统计该序列中「峰」与「谷」的数量即可，而不需要考虑「过渡元素」
 * 而不需要通过动态规划考虑不同的情况
 */

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;  // 摆动方向
        int ans = 1;
        for (int i = 1; i < len; i++) {
            // 前一个差和后一个差正负交替
            if ((flag >= 0 && nums[i] - nums[i - 1] < 0) ||
                (flag <= 0 && nums[i] - nums[i - 1] > 0)) {
                flag = nums[i] - nums[i - 1];
                ans++;
            }
        }
        return ans;
    }
};
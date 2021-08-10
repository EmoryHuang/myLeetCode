/*
 * @Descroption: LeetCode 413. 等差数列划分
 * @Author: EmoryHuang
 * @Date: 2021-08-10 13:10:26
 * @Method:
 * 动态规划
 * 考虑以nums[i]结尾的等差数列的个数
 */


class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        // 考虑以nums[i]结尾的等差数列的个数
        for (int i = 2; i < n; i++)
            if (nums[i] + nums[i - 2] == 2 * nums[i - 1]) {
                ans += ++cnt;
            } else
                cnt = 0;
        return ans;
    }
};
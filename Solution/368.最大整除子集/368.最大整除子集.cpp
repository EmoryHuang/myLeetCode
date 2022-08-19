/*
 * @Descroption: LeetCode 368. 最大整除子集
 * @Author: EmoryHuang
 * @Date: 2021-04-23 14:22:36
 * @解题思路:
 * 动态规划问题，`dp[i]` 表示以 `nums[i]` 结尾的最大整除子集的数量
 * 位置 i 的最大整除子集等于 j 从 0 到 i-1 各个位置的最大整除子集 + 1 的最大值。
 * 转移方程： `dp[i] = max(dp[i], dp[j] + 1)`
 * 同时，还要寻找这个子集中最大的元素，然后根据最大元素再次遍历，寻找所有元素
 */

class Solution {
   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<int> dp(len, 1);  // 初始为1
        int maxInd = 0;          // 子集的最大元素
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > dp[maxInd]) maxInd = i;
        }
        // 根据最大元素寻找所有元素
        vector<int> ans;
        ans.push_back(nums[maxInd]);  // 最大元素
        for (int i = len - 1; i >= 0 && dp[maxInd] > 1; i--) {
            if (dp[maxInd] - 1 == dp[i] && nums[maxInd] % nums[i] == 0) {
                ans.push_back(nums[i]);
                maxInd = i;
            }
        }
        return ans;
    }
};
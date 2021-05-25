/*
 * @Descroption: LeetCode 1800. 最大升序子数组和
 * @Author: EmoryHuang
 * @Date: 2021-05-25 12:49:11
 * @解题思路:
 * 遍历数组，若nums[i - 1] < nums[i]则累加sum，否则重新累加
 */

class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int sum = nums[0], ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
                ans = max(ans, sum);
            } else
                sum = nums[i];
        }
        return ans;
    }
};
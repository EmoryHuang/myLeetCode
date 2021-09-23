/*
 * @Descroption: LeetCode 910. 最小差值 II
 * @Author: EmoryHuang
 * @Date: 2021-09-23 18:50:41
 * @Method:
 * 贪心 + 排序
 * 排序后再次遍历，找到可能的新的最大值和最小值
 */

class Solution {
   public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            int cur = max(nums[n - 1] - k, a + k) - min(nums[0] + k, b - k);
            ans = min(ans, cur);
        }
        return ans;
    }
};
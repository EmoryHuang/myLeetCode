/*
 * @Descroption: LeetCode 1508. 子数组和排序后的区间和
 * @Author: EmoryHuang
 * @Date: 2021-08-11 14:58:42
 * @Method:
 * 暴力遍历
 * 得到所有的子数组的和之后，对数组排序，然后计算指定的下标范围内的元素之和
 */

class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % 1000000007;
        }
        return ans;
    }
};
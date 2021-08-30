/*
 * @Descroption: LeetCode 1588. 所有奇数长度子数组的和
 * @Author: EmoryHuang
 * @Date: 2021-08-29 17:21:44
 * @Method:
 * 方法一：前缀和
 * 前缀和查询区间
 *
 * 方法二：数学
 * 统计每个数字在子数组中会出现多少次
 * 位置i左边奇数个数的方案为(i+1)/2, 右边为 (n-i)/2
 * 位置i左边偶数数个数的方案为i/2, 右边为 (n-i-1)/2
 */

class Solution {
   public:
    // 方法一：前缀和
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> nums(n + 1);
    //     for (int i = 0; i < n; i++) nums[i + 1] = nums[i] + arr[i];
    //     int ans = 0;
    //     for (int l = 0; l < n; l++)
    //         for (int len = 1; l + len <= n; len += 2) {
    //             int r = l + len - 1;
    //             ans += nums[r + 1] - nums[l];
    //         }
    //     return ans;
    // }

    // 方法二：数学
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l_odd = (i + 1) / 2, r_odd = (n - i) / 2;
            int l_even = i / 2, r_even = (n - i - 1) / 2;
            l_even++, r_even++;
            ans += (l_odd * r_odd + l_even * r_even) * arr[i];
        }
        return ans;
    }
};
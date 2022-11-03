/*
 * @Descroption: LeetCode 801. 使序列递增的最小交换次数
 * @Author: EmoryHuang
 * @Date: 2022-10-10 09:45:45
 * @Method:
 * 动态规划
 * 由于只能交换同位置元素，则至少满足下列条件的一种：
 * nums1[i] > nums1[i - 1] and nums2[i] > nums2[i - 1]
 * nums1[i] > nums2[i - 1] and nums2[i] > nums1[i - 1]
 * dp[i][0] 表示到位置i序列递增的最小交换次数，不交换nums1[i]与nums2[i]
 * dp[i][1] 表示到位置i序列递增的最小交换次数，交换nums1[i]与nums2[i]
 * 空间可优化
 */

class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        // dp[i][0] 表示到位置i序列递增的最小交换次数，不交换nums1[i]与nums2[i]
        // dp[i][1] 表示到位置i序列递增的最小交换次数，交换nums1[i]与nums2[i]
        // 空间可优化
        // a, b分别表示不交换与交换的次数
        int a = 0, b = 1;
        int n = nums1.length;
        for (int i = 1; i < n; i++) {
            int at = n, bt = n;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                at = a; // 不交换
                bt = b + 1; // 交换
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                // 同时满足则取较小值
                at = Math.min(at, b);
                bt = Math.min(bt, a + 1);
            }
            a = at;
            b = bt;
        }
        return Math.min(a, b);
    }
}
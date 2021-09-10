/*
 * @Descroption: LeetCode 1818. 绝对差值和
 * @Author: EmoryHuang
 * @Date: 2021-07-14 20:18:58
 * @解题思路:
 * 二分法
 * 遍历每个序列，找到当前对应差值的绝对值 diff
 * 二分法寻找 nums1 中最接近 nums2[i] 的数字，找到后得到新的差值
 * （因为是绝对值，所以计算差值要考虑两边）
 * 记录可以减小的最大的差值
 */

class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());
        long sum = 0;
        int max_diff = 0;
        // 遍历每个序列
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i];
            if (a == b) continue;
            int diff = abs(a - b);  // 当前对应差值的绝对值
            sum += diff;            // 绝对差值和
            // 二分法寻找 nums1 中最接近 b 的数字
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (sorted[mid] <= b)
                    l = mid;
                else
                    r = mid - 1;
            }
            // 得到新的差值
            int new_diff = abs(sorted[l] - b);
            // 因为是绝对值，所以要考虑两边
            if (l + 1 < n) new_diff = min(new_diff, abs(sorted[l + 1] - b));
            // 记录可以减小的最大的差值
            if (new_diff < diff) max_diff = max(max_diff, diff - new_diff);
        }
        return (sum - max_diff) % 1000000007;
    }
};
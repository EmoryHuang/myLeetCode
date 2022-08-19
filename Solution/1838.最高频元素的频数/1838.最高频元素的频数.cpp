/*
 * @Descroption: LeetCode 1838. 最高频元素的频数
 * @Author: EmoryHuang
 * @Date: 2021-07-19 14:45:33
 * @解题思路:
 * 方法一：排序 + 滑动窗口
 * 判断当前滑动窗口是否满足条件
 * 方法二：排序 + 滑动窗口 + 二分
 * 首先，通过二分法判断当前选的频数是否可行
 * 具体来说，通过滑动窗口进行判断，由于频数固定，因此我们可以判断，当前窗口内的元素是否满足条件
 * 目标数字即为当前窗口右端点对应的数字，通过判断目标区间和即可判断当前窗口是否满足条件
 */

class Solution {
   public:
    // 方法一：排序 + 滑动窗口
    // int maxFrequency(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     int l = 0, ans = 1;
    //     long diff = 0;
    //     for (int r = 1; r < n; r++) {
    //         diff += (long)(r - l) * (nums[r] - nums[r - 1]);
    //         if (diff > k) {
    //             diff -= nums[r] - nums[l];
    //             l++;
    //         }
    //         ans = max(ans, r - l + 1);
    //     }
    //     return ans;
    // }

    // 方法二：排序 + 滑动窗口 + 二分
    int n;
    bool check(vector<int> nums, vector<long> pre, int fre, int k) {
        for (int i = 0; i < n + 1 - fre; i++) {
            int j = i + fre - 1;
            long diff = (long)fre * nums[j] - (pre[j + 1] - pre[i]);
            if (diff <= k) return true;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(nums, pre, mid, k))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
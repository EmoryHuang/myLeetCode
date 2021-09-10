/*
 * @Descroption: LeetCode 1283. 使结果不超过阈值的最小除数
 * @Author: EmoryHuang
 * @Date: 2021-07-22 20:15:22
 * @解题思路:
 * 二分法寻找左端点
 */

class Solution {
   public:
    bool check(vector<int>& nums, int threshold, int div) {
        int cnt = 0;
        for (int num : nums) cnt += ceil(1.0 * num / div);
        return cnt <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1000001;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, threshold, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
/*
 * @Descroption: LeetCode 1343. 大小为 K 且平均值大于等于阈值的子数组数目
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:27:18
 * @解题思路:
 * 简单题，固定长度的滑动窗口
 */

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s = 0;
        for (int i = 0; i < k; i++) s += arr[i];
        int ans = s / k >= threshold ? 1 : 0;
        for (int i = k; i < arr.size(); i++) {
            s += arr[i];
            s -= arr[i - k];
            ans = s / k >= threshold ? ans + 1 : ans;
        }
        return ans;
    }
};
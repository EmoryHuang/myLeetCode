/*
 * @Descroption: LeetCode 1191. K 次串联后最大子数组之和
 * @Author: EmoryHuang
 * @Date: 2021-10-15 11:18:50
 * @Method:
 * 动态规划
 * 若 k == 1, 那么就是单纯的最大子数组之和
 * 若 k == 2, 同样按照 k == 1 计算, 考虑第一部分的后缀 + 第二部分的前缀
 * 若 k > 2, 循环中间部分总和
 */

class Solution {
   public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int ans = 0, cur = 0, n = arr.size();
        int sum = 0;
        for (int num : arr) sum += num;
        for (int i = 0; i < min(2, k) * n; i++) {
            cur = max(cur + arr[i % n], arr[i % n]);
            ans = max(ans, cur);
        }
        while (sum > 0 && k-- > 2) ans = (ans + sum) % 1000000007;
        return ans % 1000000007;
    }
};
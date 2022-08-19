/*
 * @Descroption: LeetCode 829. 连续整数求和
 * @Author: EmoryHuang
 * @Date: 2022-06-03 10:50:20
 * @Method:
 * 假设某段序列首项为a，长度为k，和为n，那么根据等差数列求和有:
 * n = (2a + k - 1) * k / 2
 * a = (2n / k - k + 1) / 2
 * 因为 a ≥ 1
 * 所以 n = (2a + k - 1) * k / 2 ≥ (k + 1) * k / 2 ≥ k^2 / 2
 * 所以 k ≤ √(2n)
 */


class Solution {
   public:
    int consecutiveNumbersSum(int _n) {
        int ans = 0, n = _n * 2;
        for (int k = 1; k * k < n; ++k) {
            // 由 2n = (2a + k - 1) * k 知 2n 必定整除 k
            if (n % k != 0) continue;
            if ((n / k - k + 1) % 2 == 0) ans++;
        }
        return ans;
    }
};
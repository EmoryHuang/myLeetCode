'''
Descroption: LeetCode 829. 连续整数求和 
Author: EmoryHuang
Date: 2022-06-03 10:47:24
Method:
假设某段序列首项为a，长度为k，和为n，那么根据等差数列求和有:
n = (2a + k - 1) * k / 2
a = (2n / k - k + 1) / 2
因为 a ≥ 1
所以 n = (2a + k - 1) * k / 2 ≥ (k + 1) * k / 2 ≥ k^2 / 2
所以 k ≤ √(2n)
'''


class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        ans, n = 0, n * 2
        for k in range(1, int(math.sqrt(n)) + 1):
            # 由 2n = (2a + k - 1) * k 知 2n 必定整除 k
            if n % k != 0:
                continue
            if (n // k - k + 1) % 2 == 0:
                ans += 1
        return ans
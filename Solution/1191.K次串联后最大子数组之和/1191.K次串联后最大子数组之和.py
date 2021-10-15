'''
Descroption: LeetCode 1191. K 次串联后最大子数组之和
Author: EmoryHuang
Date: 2021-10-15 11:12:50
Method:
动态规划
若 k == 1, 那么就是单纯的最大子数组之和
若 k == 2, 同样按照 k == 1 计算, 考虑第一部分的后缀 + 第二部分的前缀
若 k > 2, 循环中间部分总和
'''


class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        mod, n = 10**9 + 7, len(arr)
        ans, cur = 0, 0
        # 若 k == 1, 那么就是单纯的最大子数组之和
        # 若 k == 2, 同样按照 k == 1 计算, 考虑第一部分的后缀 + 第二部分的前缀
        # 若 k > 2, 循环中间部分总和
        # 遍历 1 或 2 个长度的 arr
        for i in range(min(k, 2) * n):
            # 以 arr[i] 结尾的最大子数组之和
            cur = max(cur + arr[i % n], arr[i % n])
            # 最大子数组之和
            ans = max(ans, cur)
        s = sum(arr)
        while s > 0 and k > 2:
            k -= 1
            ans = (ans + s) % mod
        return ans % mod

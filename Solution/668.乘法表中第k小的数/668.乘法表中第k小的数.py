'''
Descroption: LeetCode 668. 乘法表中第k小的数
Author: EmoryHuang
Date: 2022-05-18 09:12:38
Method:
二分查找
left = 1, right = m * n + 1, mid = (left + right) // 2
每次寻找乘法表中小于等于 mid 的数的个数 cnt
若 cnt == k, 则说明找到了第 k 小的数
其中 cnt = sum_{i = 1}^{m} min(mid // i, n)
'''


class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def count(num):
            # 寻找乘法表中小于等于 num 的数的个数
            cnt = 0
            for i in range(1, m + 1):
                # i 为行号，num // i 为可能的列号
                cnt += min(num // i, n)
            return cnt

        left, right = 1, m * n + 1
        while left < right:
            mid = (left + right) // 2
            if count(mid) < k:
                left = mid + 1
            else:
                right = mid
        return left
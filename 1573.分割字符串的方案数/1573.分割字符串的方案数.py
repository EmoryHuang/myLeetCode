'''
Descroption: LeetCode 1573. 分割字符串的方案数
Author: EmoryHuang
Date: 2021-08-14 14:39:49
Method:
排列组合
计数字符串中1的位置和数量
若 1 的数量为 0，说明没有 1，那么结果为C(2,n-1)，即 (n - 1) * (n - 2) / 2
否则，考虑每两个部分之间最后一个 1 和第一个 1 的距离
然后根据排列组合原理计算
'''


class Solution:
    def numWays(self, s: str) -> int:
        ones = []
        n = len(s)
        for i, c in enumerate(s):
            if c == '1':
                ones.append(i)
        cnt = len(ones)
        if cnt % 3 != 0:
            return 0
        if cnt == 0:
            return (n - 1) * (n - 2) // 2 % 1000000007
        else:
            ind1, ind2 = cnt // 3, cnt // 3 * 2
            # 第一部分最后一个 1 和第二部分第一个 1 的距离
            cnt1 = ones[ind1] - ones[ind1 - 1]
            # 第二部分最后一个 1 和第三部分第一个 1 的距离
            cnt2 = ones[ind2] - ones[ind2 - 1]
            return cnt1 * cnt2 % 1000000007
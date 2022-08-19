'''
Descroption: LeetCode 1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
Author: EmoryHuang
Date: 2021-06-01 20:21:00
解题思路:
求出糖果数量的前缀和
由此可以得到第 i 种糖果编号范围为 [pre[i]+1, pre[i] + candiesCount[i]]
另外一方面，每天至少吃 1 颗糖果，至多吃 Capi 颗糖果
因此吃的糖果的数量落在区间 [dayi + 1, (dayi + 1) * Capi]
只要判断这两个区间是否有交集即可
'''


class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        ans = list()
        pre = [0] * (len(candiesCount) + 1)
        for i in range(len(candiesCount)):
            pre[i + 1] = pre[i] + candiesCount[i]
        for type, day, cap in queries:
            minCandy, maxCandy = day + 1, (day + 1) * cap
            firstCandy, lastCandy = pre[type] + \
                1, pre[type] + candiesCount[type]
            ans.append(lastCandy >= minCandy and firstCandy <= maxCandy)
        return ans

'''
Descroption: LeetCode 517. 超级洗衣机
Author: EmoryHuang
Date: 2021-09-29 09:25:42
Method:
贪心
首先判断是否能均分，得到目标 target
若 num - target < 0 表示需要从两边获取衣服, 否则需要向两边拿出衣服
p < 0 说明需要从右边获取衣服, p > 0 说明需要向右边拿出衣服
最大的操作次数就是 max(num - target, abs(p))
'''


class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        _sum, n = sum(machines), len(machines)
        if _sum % n != 0:
            return -1
        target = _sum // n
        ans, p = 0, 0
        for num in machines:
            # 若 num - target < 0 表示需要从两边获取衣服
            # 否则需要向两边拿出衣服
            # p < 0 说明需要从右边获取衣服
            # p > 0 说明需要向右边拿出衣服
            # 最大的操作次数就是 max(num - target, abs(p))
            p += num - target
            ans = max(ans, num - target, abs(p))
        return ans

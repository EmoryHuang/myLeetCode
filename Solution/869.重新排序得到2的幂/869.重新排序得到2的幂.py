'''
Descroption: LeetCode 869. 重新排序得到 2 的幂
Author: EmoryHuang
Date: 2021-10-28 08:59:50
Method:
打表枚举出 1e9 内所有 2 的幂
统计 n 中各个数字的个数
然后查找所有 2 的幂中是否存在一个数，它各个数字的个数与 n 相同
'''


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # 打表 2 的幂
        power = [Counter(str(1 << i)) for i in range(30)]
        # 统计 n 中各个数字的个数
        cnt = Counter(str(n))
        return any(cnt == s for s in power)
'''
Descroption: LeetCode 458. 可怜的小猪
Author: EmoryHuang
Date: 2021-11-25 08:38:14
Method:
t = minutesToTest / minutesToDie 计算出一只猪可以测试的最大次数
那么一只猪可以检验出 t + 1 个桶的水
同样的，对于 n 只猪，只需要 n 满足 (t + 1)**n >= buckets
即 n = log(buckets, (t + 1))
'''


class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        # t = minutesToTest / minutesToDie 计算出一只猪可以测试的最大次数
        # 那么一只猪可以检验出 t + 1 个桶的水
        # 同样的，对于 n 只猪，只需要 n 满足 (t + 1)**n >= buckets
        # 即 n = log(buckets, (t + 1))
        return math.ceil(math.log(buckets, minutesToTest / minutesToDie + 1))
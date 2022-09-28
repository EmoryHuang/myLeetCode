'''
Descroption: LeetCode 464. 我能赢吗
Author: EmoryHuang
Date: 2022-05-22 10:31:58
Method:
状态压缩 DP
枚举所有可能的状态，使用 memo 记录当前使用的数字并记录 total
如果当前数字已经被选过了，则跳过；如果当前数字加上之前的数字大于目标值，则赢了
'''


class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        @lru_cache(None)
        def dfs(memo, total):
            # 枚举所有可能的数字
            for i in range(maxChoosableInteger):
                # 如果当前数字已经被选过了，则跳过
                if (memo >> i) & 1 == 0:
                    # 如果当前数字加上之前的数字大于目标值，则赢了
                    if total + i + 1 >= desiredTotal or \
                        not dfs(memo | (1 << i), total + i + 1):
                        return True
            return False

        if desiredTotal == 0:
            return True
        # 如果不能达到目标，则必然不能赢
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        return dfs(0, 0)
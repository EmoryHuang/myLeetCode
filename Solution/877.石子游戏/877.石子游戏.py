'''
Descroption: LeetCode 877. 石子游戏
Author: EmoryHuang
Date: 2021-06-16 11:48:00
解题思路:
区间动态规划
dp[i][j] 表示当剩下的石子堆为下标 i 到下标 j 时，当前玩家与另一个玩家的石子数量之差的最大值
状态转移方程：
dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
若 dp[0][n-1] > 0 则表示亚历克斯胜利

由于石子的堆数为偶数，对于先手而言：每一次的决策局面，都能「自由地」选择奇数还是偶数的序列，
从而限制后手下一次「只能」奇数还是偶数石子。

具体的，对于本题，由于石子堆数为偶数，
因此先手的最开始局面必然是 [奇数, 偶数][奇数,偶数]，即必然是「奇偶性不同的局面」；
当先手决策完之后，交到给后手的要么是 [奇数,奇数][奇数,奇数] 或者 [偶数,偶数][偶数,偶数]，
即必然是「奇偶性相同的局面」；后手决策完后，又恢复「奇偶性不同的局面」交回到先手 ...

因此先手只需要在进行第一次操作前计算原序列中「奇数总和」和「偶数总和」哪个大，
然后每一次决策都「限制」对方只能选择「最优奇偶性序列」的对立面即可。
'''


class Solution:
    # 动态规划
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0]*(n + 1) for _ in range(n + 1)]
        for l in range(n):  # 枚举区间长度
            for i in range(n - l):  # 枚举左端点
                j = i + l
                dp[i][j] = max(piles[i] - dp[i + 1][j],
                               piles[j] - dp[i][j - 1])
        return dp[0][n - 1] > 0

    # 数学
    # def stoneGame(self, piles: List[int]) -> bool:
    #     return True
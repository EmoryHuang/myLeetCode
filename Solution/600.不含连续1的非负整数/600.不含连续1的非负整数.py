'''
Descroption: LeetCode 600. 不含连续1的非负整数
Author: EmoryHuang
Date: 2021-09-11 18:25:30
Method:
动态规划
计算不包含连续 1 的从根结点到叶结点的路径数量时，
可以不断地将字典树拆分为根结点为 0 的满二叉树和根结点不定的完全二叉树

dp[i] 表示从低位到高位，前 i 个二进制数能产生的合法数字
对于高度为 i，根节点为 0 的01字典树来说
显然有 dp[i][0] = dp[i-1][0] + dp[i-1][1]，即左右子树上满足条件的数量
同时由于不含连续1，有 dp[i-1][1] = dp[i-2][0]
因此可以得到状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
'''


class Solution:
    def findIntegers(self, n: int) -> int:
        # dp[i] 表示从低位到高位，前 i 个二进制数能产生的合法数字
        dp = [0] * 31
        dp[0], dp[1] = 1, 1

        # 对于高度为 i，根节点为 0 的01字典树来说
        # 显然有 dp[i][0] = dp[i-1][0] + dp[i-1][1]，即左右子树上满足条件的数量
        # 同时由于不含连续1，有 dp[i-1][1] = dp[i-2][0]
        # 因此可以得到状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
        for i in range(2, 31):
            dp[i] = dp[i - 1] + dp[i - 2]

        pre, ans = 0, 0
        for i in range(29, -1, -1):
            cur = (1 << i) & n  # 当前位
            if cur:
                # 当前位为 1，无左子树
                ans += dp[i + 1]  # 加上满二叉树的情况
                if pre == 1:  # 上一层为 1
                    break
                pre = 1
            else:
                # 当前位为 0，无右子树
                pre = 0
            if i == 0:  # 为 0 的情况
                ans += 1
        return ans

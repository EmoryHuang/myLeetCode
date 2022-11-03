'''
Descroption: LeetCode 940. 不同的子序列 II
Author: EmoryHuang
Date: 2022-10-14 09:28:55
Method:
动态规划
设 dp[i] 为前 i 个字符可以组成的不同的子序列
显然有，dp[i] = dp[i - 1] + newCount - repeatCount
其中 newCount 为加上 s[i] 后新增的子序列个数，即 dp[i - 1]
repeatCount 为重复的子序列个数
以 'abcb' 为例，当遍历到第二个 b 时, 以第一个 b 为结尾的子序列的数目就是重复值
那么就可以记录上一个以字符 a,b,...,z 结尾的子序列的数目
'''


class Solution:

    def distinctSubseqII(self, s: str) -> int:
        # 记录上一个以字符 a,b,...,z 结尾的子序列的数目
        pre_cnt = [0] * 26
        cur, MOD = 1, 10**9 + 7
        for ch in s:
            # 新增序列数为
            # 重复序列数为上一个以 ch 结尾的子序列的数目
            new_add, repeat = cur, pre_cnt[ord(ch) - ord('a')]
            # 当前序列数 = 之前序列数 + 新增序列数 - 重复序列数
            cur = (cur + new_add - repeat) % MOD
            # 更新以 ch 结尾的子序列的数目
            pre_cnt[ord(ch) - ord('a')] = new_add % MOD
        # 减去空串
        return cur - 1

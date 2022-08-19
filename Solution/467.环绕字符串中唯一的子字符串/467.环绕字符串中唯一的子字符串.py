'''
Descroption: LeetCode 467. 环绕字符串中唯一的子字符串
Author: EmoryHuang
Date: 2022-05-25 09:11:47
Method:
动态规划
dp[i] 表示以 i 结尾的子串的最长长度
如果有重叠，只需要考虑最长的一个，因为它覆盖了所有可能的子字符串
具体来说，遍历 p，并维护连续递增的子串长度
如果当前字符与上一个字符在 s 中连续，那么以当前字符结尾的最长长度就从前面累加，否则就是新的开始。
'''


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        n = len(p)
        if n < 1: return 0
        # dp[i] 表示以 i 结尾的子串的最长长度
        # 如果有重叠，只需要考虑最长的一个，因为它覆盖了所有可能的子字符串
        dp = [0] * 26
        # 维护连续递增的子串长度
        max_len = 0
        for i in range(n):
            # 判断是否在循环子串中
            if i > 0 and (ord(p[i]) - ord(p[i - 1])) % 26 == 1:
                max_len += 1
            else:
                max_len = 1
            dp[ord(p[i]) - ord('a')] = max(dp[ord(p[i]) - ord('a')], max_len)
        return sum(dp)

'''
Descroption: LeetCode 1513. 仅含 1 的子串数
Author: EmoryHuang
Date: 2021-08-11 14:41:37
Method:
简单题，数学，统计连续字串可组成的仅含 1 的子串数
'''


class Solution:
    def numSub(self, s: str) -> int:
        ans, cnt = 0, 0
        for c in s:
            if c == '1':
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans % 1000000007

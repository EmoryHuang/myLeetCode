'''
Descroption: LeetCode 1456. 定长子串中元音的最大数目
Author: EmoryHuang
Date: 2021-08-08 14:49:14
Method:
滑动窗口，统计窗口内元音字母的数目，记录最大值
'''


class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ls = ['a', 'e', 'i', 'o', 'u']
        l, r = 0, 0
        ans, cnt = 0, 0
        while r < len(s):
            if s[r] in ls:
                cnt += 1
                ans = max(ans, cnt)
            r += 1
            if r - l >= k:
                if s[l] in ls:
                    cnt -= 1
                l += 1
        return ans

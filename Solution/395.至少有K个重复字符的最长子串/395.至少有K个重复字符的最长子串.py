'''
Descroption: LeetCode 395. 至少有 K 个重复字符的最长子串
Author: EmoryHuang
Date: 2021-10-13 19:03:28
Method:
双指针
由于只会出现小写字母，可以遍历出现字母的数量
记录有多少字符符合要求，当区间内所有字符都符合时更新答案
'''

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        ans = 0
        # 遍历出现字母的数量
        for p in range(1, 27):
            hash = defaultdict(int)
            l, r = 0, 0
            # cnt 表示出现的字母数量，total 表示满足条件的字母数量
            cnt, total = 0, 0
            for r in range(len(s)):
                hash[s[r]] += 1
                if hash[s[r]] == 1:  # 出现了新字母
                    cnt += 1
                if hash[s[r]] == k:  # 出现了满足条件的字母
                    total += 1
                # 出现字母的数量大于 p
                while cnt > p:
                    hash[s[l]] -= 1
                    if hash[s[l]] == 0:
                        cnt -= 1
                    if hash[s[l]] == k - 1:
                        total -= 1
                    l += 1  # 左指针右移
                if cnt == total:
                    ans = max(ans, r - l + 1)
        return ans
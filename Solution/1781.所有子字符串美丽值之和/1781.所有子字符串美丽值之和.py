'''
Descroption: LeetCode 1781. 所有子字符串美丽值之和
Author: EmoryHuang
Date: 2022-12-12 09:32:50
Method:
遍历所有子字符串，使用哈希表记录字符的出现次数并计算美丽值
'''


class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            cnt = Counter()
            mx = 0
            for j in range(i, len(s)):
                cnt[s[j]] += 1
                mx = max(mx, cnt[s[j]])
                ans += mx - min(cnt.values())
        return ans
'''
Descroption: LeetCode 2287. 重排字符形成目标字符串
Author: EmoryHuang
Date: 2023-01-13 09:49:30
Method:
哈希表记录target和s中数字出现次数
'''


class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        ans = float('inf')
        cnt = Counter(s)
        for c, num in Counter(target).items():
            ans = min(ans, cnt[c] // num)
            if ans == 0:
                return 0
        return ans

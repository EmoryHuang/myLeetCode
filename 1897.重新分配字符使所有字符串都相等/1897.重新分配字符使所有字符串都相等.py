'''
Descroption: LeetCode 1897. 重新分配字符使所有字符串都相等
Author: EmoryHuang
Date: 2021-07-20 19:58:39
解题思路:
使用哈希表记录每个字符的数量
若字符的个数不是数组长度的整数倍，则满足
'''


class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        mp = defaultdict(int)
        for word in words:
            for ch in word:
                mp[ch] += 1
        for ch in mp:
            if mp[ch] % len(words) != 0:
                return False
        return True

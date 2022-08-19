'''
Descroption: LeetCode 424. 替换后的最长重复字符
Author: EmoryHuang
Date: 2021-07-31 14:55:12
Method:
滑动窗口 + 哈希表
使用哈希表记录字符出现的次数，维护字符串出现次数最大的值 maxn
若排除 maxn 个相同字符后，滑动窗口内仍有大于 k 个不同的字符，则左端点右移
'''


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, r = 0, 0
        n = len(s)
        hash = [0] * 26
        maxn = 0
        while r < n:
            # 记录字符出现的次数
            hash[ord(s[r]) - ord('A')] += 1
            # 找到字符出现次数最大的值
            # 滑动窗口只会变大或不变
            maxn = max(maxn, hash[ord(s[r]) - ord('A')])
            # 若排除 maxn 个相同字符后仍有大于 k 个不同的字符
            if r - l + 1 - maxn > k:
                # 因为窗口左端点要右移，因此要减去
                hash[ord(s[l]) - ord('A')] -= 1
                l += 1
            r += 1
        return r - l

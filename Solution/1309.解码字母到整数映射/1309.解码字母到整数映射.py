'''
Descroption: LeetCode 1309. 解码字母到整数映射
Author: EmoryHuang
Date: 2021-10-20 08:59:55
Method:
简单题，倒序遍历，将整数转为字母
'''


class Solution:
    def freqAlphabets(self, s: str) -> str:
        idx = len(s) - 1
        ans = []
        # 倒序遍历
        while idx >= 0:
            if s[idx] == '#':
                c = chr(int(s[idx - 2:idx]) + ord('a') - 1)
                idx -= 2
            else:
                c = chr(int(s[idx]) + ord('a') - 1)
            ans.append(c)
            idx -= 1
        return ''.join(ans[::-1])
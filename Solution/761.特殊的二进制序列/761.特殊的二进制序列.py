'''
Descroption: LeetCode 761. 特殊的二进制序列
Author: EmoryHuang
Date: 2022-08-08 09:15:09
Method:
每个特殊的二进制序列必定以1开头，以0结尾
通过维护计数器cnt统计1与0数量的差值
若cnt == 0，则递归地生成子序列
'''


class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if len(s) <= 2:
            return s
        res = []
        cnt, left = 0, 0
        for i, ch in enumerate(s):
            if ch == '1':
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    res.append('1' + self.makeLargestSpecial(s[left + 1:i]) + '0')
                    left = i + 1
        return ''.join(sorted(res, reverse=True))
'''
Descroption: LeetCode 1309. ������ĸ������ӳ��
Author: EmoryHuang
Date: 2021-10-20 08:59:55
Method:
���⣬���������������תΪ��ĸ
'''


class Solution:
    def freqAlphabets(self, s: str) -> str:
        idx = len(s) - 1
        ans = []
        # �������
        while idx >= 0:
            if s[idx] == '#':
                c = chr(int(s[idx - 2:idx]) + ord('a') - 1)
                idx -= 2
            else:
                c = chr(int(s[idx]) + ord('a') - 1)
            ans.append(c)
            idx -= 1
        return ''.join(ans[::-1])
'''
Descroption: LeetCode 1456. �����Ӵ���Ԫ���������Ŀ
Author: EmoryHuang
Date: 2021-08-08 14:49:14
Method:
�������ڣ�ͳ�ƴ�����Ԫ����ĸ����Ŀ����¼���ֵ
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

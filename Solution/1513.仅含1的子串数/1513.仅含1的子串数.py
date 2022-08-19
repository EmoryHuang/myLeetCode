'''
Descroption: LeetCode 1513. ���� 1 ���Ӵ���
Author: EmoryHuang
Date: 2021-08-11 14:41:37
Method:
���⣬��ѧ��ͳ�������ִ�����ɵĽ��� 1 ���Ӵ���
'''


class Solution:
    def numSub(self, s: str) -> int:
        ans, cnt = 0, 0
        for c in s:
            if c == '1':
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans % 1000000007

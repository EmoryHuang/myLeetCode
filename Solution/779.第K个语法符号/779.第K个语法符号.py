'''
Descroption: LeetCode 779. ��K���﷨����
Author: EmoryHuang
Date: 2021-09-15 19:10:55
Method:
�ݹ�
ÿһ�еĺ�벿��������ǰ�벿�ֵķ�ת
'''


class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        # ��� k ��ǰ���
        if k <= 2**(n - 2):
            return self.kthGrammar(n - 1, k)
        # ��� k �ں���
        return self.kthGrammar(n - 1, k - 2**(n - 2)) ^ 1

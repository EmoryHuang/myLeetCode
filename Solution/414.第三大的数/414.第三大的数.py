'''
Descroption: LeetCode 414. ���������
Author: EmoryHuang
Date: 2021-10-06 14:30:25
Method:
����һ�λ�ȡ���ֵ���δ�ֵ��������ֵ
������һ�������ֵ����ֱ��ֵ���д���
'''


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a, b, c = float('-inf'), float('-inf'), float('-inf')
        for num in nums:
            if num == a or num == b or num == c:
                continue
            if num > a:
                a, b, c = num, a, b
            elif num > b:
                b, c = num, b
            elif num > c:
                c = num
        if c != float('-inf'):
            return c
        return a
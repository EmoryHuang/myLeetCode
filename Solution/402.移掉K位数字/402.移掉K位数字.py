'''
Descroption: LeetCode 402. �Ƶ� K λ����
Author: EmoryHuang
Date: 2021-08-03 14:11:05
Method:
�����ַ���ά��һ������ջ������k�ε���
���Ҫע��ص��ַ�����ߵ�ǰ��0
'''


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        remain = len(num) - k
        for n in num:
            # ά��һ������ջ
            while k and stack and stack[-1] > n:
                stack.pop()
                k -= 1
            stack.append(n)
        return ''.join(stack[:remain]).lstrip('0') or '0'

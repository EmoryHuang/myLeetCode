'''
Descroption: LeetCode 386. �ֵ�������
Author: EmoryHuang
Date: 2022-04-18 08:45:34
Method:
dfs
���ڵ�ǰ���� num
�� num * 10 <= n, ����һ������Ϊ num * 10
���������ֵ, �� num % 10 == 9 or num + 1 > n, ���˻���һλ
������һ������Ϊ num + 1
'''


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [0] * n
        num = 1
        for i in range(n):
            ans[i] = num
            if num * 10 <= n:
                num *= 10
            else:
                # �������ֵ�����˻���һλ
                while num % 10 == 9 or num + 1 > n:
                    num //= 10
                # ���û�е������ֵ����� 1
                num += 1
        return ans
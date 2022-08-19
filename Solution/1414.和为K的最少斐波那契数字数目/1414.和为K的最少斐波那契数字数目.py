'''
Descroption: LeetCode 1414. ��Ϊ K ������쳲�����������Ŀ
Author: EmoryHuang
Date: 2021-06-05 15:25:00
����˼·:
̰��˼�룬�Ӵ�Сѡ��쳲���������
'''


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a, b, count = 1, 1, 0
        f = [a, b]
        while a + b <= k:
            f.append(a + b)
            a, b = b, a + b
        for num in f[::-1]:
            if k >= num:
                k -= num
                count += 1
        return count

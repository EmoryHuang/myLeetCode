'''
Descroption: LeetCode 829. ����������� 
Author: EmoryHuang
Date: 2022-06-03 10:47:24
Method:
����ĳ����������Ϊa������Ϊk����Ϊn����ô���ݵȲ����������:
n = (2a + k - 1) * k / 2
a = (2n / k - k + 1) / 2
��Ϊ a �� 1
���� n = (2a + k - 1) * k / 2 �� (k + 1) * k / 2 �� k^2 / 2
���� k �� ��(2n)
'''


class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        ans, n = 0, n * 2
        for k in range(1, int(math.sqrt(n)) + 1):
            # �� 2n = (2a + k - 1) * k ֪ 2n �ض����� k
            if n % k != 0:
                continue
            if (n // k - k + 1) % 2 == 0:
                ans += 1
        return ans
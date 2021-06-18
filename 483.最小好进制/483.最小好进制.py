'''
Descroption: LeetCode 483. ��С�ý���
Author: EmoryHuang
Date: 2021-06-18 17:09:00
����˼·:
�� n �� k ���Ƴ���Ϊ len����ô�� (n)10 = (11..1)k = k^0 + k^1 + ... + k^(len-1)
len = 1 ʱ, k^0 = 1, n = 1, �����ⲻ��;
len = 2 ʱ, k^0 + k^1 = n, k = n - 1 �� 2
��� len �� 2
�� s = len - 1
���ݶ���ʽ������з��������Եõ���k^s < n < (k+1)^s
�� k < n^(1/s) < k+1
����ֻ��Ҫ��֤ n^(1/s) �Ƿ�Ϊ���������ɡ�
'''


class Solution:
    # ��ѧ����
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)
        for i in range(num.bit_length(), 2, -1):
            # k < n^(1/s) < k+1
            k = int(pow(num, 1/(i - 1)))
            # ��� i �� 1 �Ƿ�Ϊ n
            if num == (pow(k, i) - 1) // (k - 1):
                return str(k)
        return str(num - 1)

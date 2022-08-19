'''
Descroption: LeetCode 233. ���� 1 �ĸ���
Author: EmoryHuang
Date: 2021-08-13 20:14:28
Method:
�ֱ�������ʮ���١�ǧ...λ��1���ֵĴ���
'''


class Solution:
    def countDigitOne(self, n: int) -> int:
        # lowΪ��λ��curΪ��ǰλ��highΪ��λ
        low, cur, high = 0, n % 10, n // 10
        # �Ӹ�λ��ʼ
        d = 1
        ans = 0
        while high or cur:
            if cur == 0:
                # ��ǰλΪ 0����ôֻ�ܿ���λ����high��ȡ��
                ans += high * d
            elif cur == 1:
                # ��ǰλΪ 1���ڸ�λ�Ļ������ټ��ϵ�λ
                # ��Ϊ��ǰλΪ 1 �� low ����ʲô���֣������ 1 �й���
                ans += high * d + low + 1
            elif cur > 1:
                # ��ǰλ���� 1����ѵ�ǰλ����high
                ans += (high + 1) * d
            low += cur * d
            d *= 10  # ��һλ
            cur = high % 10
            high = high // 10
        return ans

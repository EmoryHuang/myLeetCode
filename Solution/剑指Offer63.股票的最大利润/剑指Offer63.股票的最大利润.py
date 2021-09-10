'''
Descroption: ��ָ Offer 63. ��Ʊ���������
Author: EmoryHuang
Date: 2021-07-04 13:56:55
����˼·:
��Ϊ�����һ����������֮ǰ�����ά��һ����Сֵ�������۸�Ѱ���������
'''


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        ans, min = 0, math.inf
        for price in prices:
            if price < min:
                min = price
            else:
                ans = max(ans, price - min)
        return ans

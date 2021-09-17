'''
Descroption: LeetCode 1423. �ɻ�õ�������
Author: EmoryHuang
Date: 2021-09-17 19:22:08
Method:
��������
�������ڴ�СΪ n - k
��֤����������Ԫ����С��Ҳ����ʣ�µ�Ԫ����С
'''


class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        # �������ڴ�СΪ n - k
        r = sum(cardPoints[:(n - k)])
        ans = r
        for i in range(n - k, n):
            r += cardPoints[i] - cardPoints[i - n + k]
            # ��֤����������Ԫ����С��Ҳ����ʣ�µ�Ԫ����С
            ans = min(ans, r)
        return sum(cardPoints) - ans

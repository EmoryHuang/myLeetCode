'''
Descroption: LeetCode 1191. K �δ��������������֮��
Author: EmoryHuang
Date: 2021-10-15 11:12:50
Method:
��̬�滮
�� k == 1, ��ô���ǵ��������������֮��
�� k == 2, ͬ������ k == 1 ����, ���ǵ�һ���ֵĺ�׺ + �ڶ����ֵ�ǰ׺
�� k > 2, ѭ���м䲿���ܺ�
'''


class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        mod, n = 10**9 + 7, len(arr)
        ans, cur = 0, 0
        # �� k == 1, ��ô���ǵ��������������֮��
        # �� k == 2, ͬ������ k == 1 ����, ���ǵ�һ���ֵĺ�׺ + �ڶ����ֵ�ǰ׺
        # �� k > 2, ѭ���м䲿���ܺ�
        # ���� 1 �� 2 �����ȵ� arr
        for i in range(min(k, 2) * n):
            # �� arr[i] ��β�����������֮��
            cur = max(cur + arr[i % n], arr[i % n])
            # ���������֮��
            ans = max(ans, cur)
        s = sum(arr)
        while s > 0 and k > 2:
            k -= 1
            ans = (ans + s) % mod
        return ans % mod

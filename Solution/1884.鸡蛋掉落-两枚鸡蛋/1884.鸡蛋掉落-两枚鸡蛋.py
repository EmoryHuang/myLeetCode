'''
Descroption: LeetCode 1884. ��������-��ö����
Author: EmoryHuang
Date: 2021-07-20 19:40:55
����˼·:
��̬�滮
dp[i]��ʾ¥�� i ����һö����û��ʱ����С��������
�����һö������ j �����ˣ���ô��ʣһö��������ʱȷ�� f ����Ҫ�ӵ� 1 ����������ӵ� j ��
�����һö������ j ��û�飬��ô��Ҫ���� i-j ������ö����ʱ�Ĳ����������ټ��ϵ�ǰ��β���
'''


class Solution:
    def twoEggDrop(self, n: int) -> int:
        dp = [1001] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                dp[i] = min(dp[i], max(j, dp[i - j] + 1))
        return dp[n]

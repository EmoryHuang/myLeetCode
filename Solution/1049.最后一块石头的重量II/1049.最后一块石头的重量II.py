'''
Descroption: LeetCode 1049. ���һ��ʯͷ������ II
Author: EmoryHuang
Date: 2021-06-08 15:22:00
����˼·:
01��������
������Գ���Ϊ�� n ��ʯͷ��Ϊ���ѣ�����������ʯͷ�����ܺ͵���С��ֵ
������˵���� stones ������ѡ�񣬴ճ��ܺͲ����� sum/2 ������ֵ��
'''


class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = sum(stones)
        # ������������Ϊʯͷ��������һ��
        dp = [0 for _ in range(s // 2 + 1)]
        for stone in stones:
            for j in range(s // 2, stone - 1, -1):  # �������
                dp[j] = max(dp[j], dp[j - stone] + stone)
        return s - dp[s // 2] * 2

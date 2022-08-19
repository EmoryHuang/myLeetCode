'''
Descroption: LeetCode 1449. ��λ�ɱ���ΪĿ��ֵ���������
Author: EmoryHuang
Date: 2021-06-12 21:58:00
����˼·:
��ȫ��������
����������λ����ͬ��λ�������������Ȼ����λ��С��������
���������Ҫ�ȼ�������Եõ������������λ��
dp[j]��ʾ�ܳɱ�ǡ��Ϊ j ʱ���λ��
״̬ת�Ʒ��̣�dp[j] = max(dp[j], dp[j - cost] + 1)
Ӧ�þ������ø�λ����ֵԽ��Խ�ã�
������ǿ��Դ���ֵ 9 ��ʼ����ֵ 1 ���������״̬�ܹ��ɸ���ֵת�ƶ�������ѡ�����ֵ
'''


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        # dp[j]��ʾ�ܳɱ�ǡ��Ϊ j ʱ���λ��
        dp = [float("-inf")] * (target + 1)
        dp[0] = 0
        for c in cost:
            for j in range(c, target + 1):
                dp[j] = max(dp[j], dp[j - c] + 1)
        if dp[target] < 0:
            return "0"
        ans = ""
        j = target
        # �Ӻ���ǰ������cost�Ϊ9
        for i in range(8, -1, -1):
            while j >= cost[i] and dp[j] == dp[j - cost[i]] + 1:
                ans += str(i + 1)
                j -= cost[i]
        return ans

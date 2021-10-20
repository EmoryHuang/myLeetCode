'''
Descroption: LeetCode 1024. ��Ƶƴ��
Author: EmoryHuang
Date: 2021-10-20 20:24:35
Method:
����һ����̬�滮
dp[i] ��ʾ������ [0, i) ������Ҫ����С����
״̬ת�Ʒ��̣�dp[i] = min(dp[i], dp[l] + 1)

��������̰��
ʹ�� maxr[i] ��ʾ��˵� i ���ܹ����������λ��
̰�ı���ÿ��λ�ã����ﵱǰλ���ܹ��ﵽ����Զλ��
'''


class Solution:
    # ����һ����̬�滮
    # def videoStitching(self, clips: List[List[int]], time: int) -> int:
    #     # dp[i] ��ʾ������ [0, i) ������Ҫ����С����
    #     dp = [float('inf')] * (time + 1)
    #     dp[0] = 0
    #     for i in range(1, time + 1):
    #         for l, r in clips:
    #             if l < i <= r:
    #                 dp[i] = min(dp[i], dp[l] + 1)
    #     if dp[time] == float('inf'):
    #         return -1
    #     return dp[time]

    # ��������̰��
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        ans, pre, last = 0, 0, 0
        # maxr[i] ��ʾ��˵� i ���ܹ����������λ��
        maxr = [0] * time
        for l, r in clips:
            if l < time:
                maxr[l] = max(maxr[l], r)
        # ����ÿ��λ��
        for i in range(time):
            last = max(last, maxr[i])
            if i == last:
                # ��һ��λ���޷�������
                return -1
            if i == pre:
                # ��������һ��λ��
                pre = last
                ans += 1
        return ans
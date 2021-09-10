'''
Descroption: LeetCode 646. �������
Author: EmoryHuang
Date: 2021-06-14 13:55:00
����˼·:
����һ��̰��˼�룬
�����Եĵڶ���ֵ��С��������
Ȼ��Ƚ� pairs[i][0] �� pre �Ĵ�С
 *
����������̬�滮
dp[i]��ʾ�� pairs[i] ��β������ĳ���
״̬ת�Ʒ��̣�dp[i] = max(dp[i], dp[j] + 1)
'''


class Solution:
    # ����һ��̰��
    # def findLongestChain(self, pairs: List[List[int]]) -> int:
    #     pairs.sort(key=lambda x: (x[1], x[0]))
    #     pre, ans = pairs[0][1], 1
    #     for i in range(1, len(pairs)):
    #         if pairs[i][0] > pre:
    #             ans += 1
    #             pre = pairs[i][1]
    #     return ans

    # ����������̬�滮
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: (x[0], x[1]))
        # dp[i]��ʾ�� pairs[i] ��β������ĳ���
        dp = [1] * len(pairs)
        for i in range(1, len(pairs)):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

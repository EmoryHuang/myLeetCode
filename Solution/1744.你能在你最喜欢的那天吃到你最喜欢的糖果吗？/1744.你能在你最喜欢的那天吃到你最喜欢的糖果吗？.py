'''
Descroption: LeetCode 1744. ����������ϲ��������Ե�����ϲ�����ǹ���
Author: EmoryHuang
Date: 2021-06-01 20:21:00
����˼·:
����ǹ�������ǰ׺��
�ɴ˿��Եõ��� i ���ǹ���ŷ�ΧΪ [pre[i]+1, pre[i] + candiesCount[i]]
����һ���棬ÿ�����ٳ� 1 ���ǹ�������� Capi ���ǹ�
��˳Ե��ǹ��������������� [dayi + 1, (dayi + 1) * Capi]
ֻҪ�ж������������Ƿ��н�������
'''


class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        ans = list()
        pre = [0] * (len(candiesCount) + 1)
        for i in range(len(candiesCount)):
            pre[i + 1] = pre[i] + candiesCount[i]
        for type, day, cap in queries:
            minCandy, maxCandy = day + 1, (day + 1) * cap
            firstCandy, lastCandy = pre[type] + \
                1, pre[type] + candiesCount[type]
            ans.append(lastCandy >= minCandy and firstCandy <= maxCandy)
        return ans

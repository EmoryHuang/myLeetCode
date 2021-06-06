'''
Descroption: LeetCode 986. �����б�Ľ���
Author: EmoryHuang
Date: 2021-06-06 15:28:00
����˼·:
������ָ�룬�ֱ�ɨ�� A��B ���飬��������������Ҷˣ����һ����������
�����������ˣ�ȡ���ǵĽϴ���
����������Ҷˣ�ȡ���ǵĽ�С��
����һ����������󣬽�������������䣬ָ���ƶ�
'''


class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        ans = []
        m, n = len(firstList), len(secondList)
        i, j = 0, 0
        while i < m and j < n:
            left = max(firstList[i][0], secondList[j][0])
            right = min(firstList[i][1], secondList[j][1])
            if left <= right:
                ans.append([left, right])  # ȡ����
            # �Ҷ˴������
            if firstList[i][1] < secondList[j][1]:
                i += 1
            else:
                j += 1
        return ans

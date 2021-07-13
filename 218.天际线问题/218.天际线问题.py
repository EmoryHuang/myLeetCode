'''
Descroption: LeetCode 218. ���������
Author: EmoryHuang
Date: 2021-07-13 19:47:32
����˼·:
ά��һ������ѣ��������ж˵�
�������˵㣬����߶ȼ�������
������Ҷ˵㣬����߶��Ƴ������
ÿ��ȡ��ǰ���ֵ����һ�����ֵ�Ƚ�
'''

from sortedcontainers import SortedList


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans = []
        points = []
        # Ϊ�˷������򣬶�����˵㣬��߶�Ϊ���������Ҷ˵���߶�Ϊ��
        for l, r, h in buildings:
            points.append((l, -h))
            points.append((r, h))
        # ���պ������������
        # �����������ͬ��������˵�����
        # �����ͬ����/�Ҷ˵㣬���ո߶Ƚ�������
        points.sort()
        pre = 0
        q = SortedList([pre])
        # �������ж˵�
        for point, height in points:
            if height < 0:  # �������˵㣬���������
                q.add(-height)
            else:  # ������Ҷ˵㣬���Ƴ������
                q.remove(height)
            # ȡ��ǰ���ֵ�Ƚ�
            cur = q[-1]
            if cur != pre:
                ans.append([point, cur])
                pre = cur
        return ans
'''
Descroption: LeetCode 452. �����������ļ���������
Author: EmoryHuang
Date: 2021-08-12 19:56:40
Method:
̰��
�����Ҷ˵�����
����˵���֮ǰ������ֵ���Ƚϣ��ҵ���ǰ�����������������
'''


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0
        # �����Ҷ˵�����
        points.sort(key=lambda x: x[1])
        pre = points[0][1]
        ans = 1
        for l, r in points:
            # �ҵ���ǰ�����������������
            if l > pre:
                ans += 1
                pre = r
        return ans
'''
Descroption: LeetCode 1725. �����γ���������εľ�����Ŀ
Author: EmoryHuang
Date: 2022-02-04 10:18:25
Method:
���⣬ö��ÿ���������г�����������α߳���Ȼ�������ֵ������
'''


class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        e = [min(w, l) for w, l in rectangles]
        return e.count(max(e))

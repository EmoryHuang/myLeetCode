'''
Descroption: LeetCode 2001. �ɻ������ε�����
Author: EmoryHuang
Date: 2021-10-08 19:06:37
Method:
��ϣ���¼��߱���ͬ�ľ��ε�����
'''


class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        hash = defaultdict(int)
        for w, h in rectangles:
            hash[w / h] += 1
        ans = 0
        for key, val in hash.items():
            if val > 1:
                ans += val * (val - 1) / 2
        return int(ans)
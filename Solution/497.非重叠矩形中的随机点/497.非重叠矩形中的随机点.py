'''
Descroption: LeetCode 497. ���ص������е������
Author: EmoryHuang
Date: 2022-06-09 09:00:58
Method:
ǰ׺�� + ����
������θ��ǵ��ǰ׺�ͣ�֮������������
ͨ�����ֲ��ҳ���������ڵľ��Σ��Լ�������ھ����е�λ��
'''


class Solution:
    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.sum = [0]
        # ������θ��ǵ��ǰ׺��
        for a, b, c, d in rects:
            self.sum.append(self.sum[-1] + (c - a + 1) * (d - b + 1))

    def pick(self) -> List[int]:
        # ���ȡ��
        r = randrange(self.sum[-1])
        # ���ֲ��Ҿ���
        rect_idx = bisect.bisect_right(self.sum, r) - 1
        # ȷ�����λ��
        a, b, c, d = self.rects[rect_idx]
        ra, rb = divmod(r - self.sum[rect_idx], (d - b + 1))
        return [a + ra, b + rb]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
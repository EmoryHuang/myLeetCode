'''
Descroption: LeetCode 497. 非重叠矩形中的随机点
Author: EmoryHuang
Date: 2022-06-09 09:00:58
Method:
前缀和 + 二分
计算矩形覆盖点的前缀和，之后随机点的数量
通过二分查找出这个点所在的矩形，以及这个点在矩形中的位置
'''


class Solution:
    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.sum = [0]
        # 计算矩形覆盖点的前缀和
        for a, b, c, d in rects:
            self.sum.append(self.sum[-1] + (c - a + 1) * (d - b + 1))

    def pick(self) -> List[int]:
        # 随机取点
        r = randrange(self.sum[-1])
        # 二分查找矩形
        rect_idx = bisect.bisect_right(self.sum, r) - 1
        # 确定点的位置
        a, b, c, d = self.rects[rect_idx]
        ra, rb = divmod(r - self.sum[rect_idx], (d - b + 1))
        return [a + ra, b + rb]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
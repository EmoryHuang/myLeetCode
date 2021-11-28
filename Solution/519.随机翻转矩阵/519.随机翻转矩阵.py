'''
Descroption: LeetCode 519. 随机翻转矩阵
Author: EmoryHuang
Date: 2021-11-27 08:44:42
Method:
随机选取数字作为一维数组的索引位置，使用集合记录翻转过的元素位置，如新选择的位置已经处理过，继续选数
'''


class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.s = set()

    def flip(self) -> List[int]:
        # 随机选取数字作为索引
        idx = random.randint(0, self.m * self.n - 1)
        while idx in self.s:
            idx = random.randint(0, self.m * self.n - 1)
        self.s.add(idx)
        return [idx // self.n, idx % self.n]

    def reset(self) -> None:
        self.s.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()
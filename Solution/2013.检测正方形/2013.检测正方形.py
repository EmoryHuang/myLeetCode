'''
Descroption: LeetCode 2013. 检测正方形
Author: EmoryHuang
Date: 2022-01-26 11:06:28
Method:
使用哈希表存储点 {x, {y: 点(x, y)出现次数}}
传入的点为 (x, y)，先查询 x 行都有哪些列，即枚举点 (x, ny)
由此可以得到正方形边长 d
而后再寻找 (x ± d, y) 和 (x ± d, ny)
应用乘法原理，即可知道该正方形的方案数
'''

class DetectSquares:
    def __init__(self):
        self.map = defaultdict(Counter)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.map[x][y] += 1

    def count(self, point: List[int]) -> int:
        ans = 0
        x, y, = point
        if x not in self.map:
            return 0
        xcnt = self.map[x]
        for c, ccnt in self.map.items():
            if c != x:
                d = c - x  # 边长
                # 乘法原理计算所有出现次数
                ans += ccnt[y] * ccnt[y + d] * xcnt[y + d]
                ans += ccnt[y] * ccnt[y - d] * xcnt[y - d]
        return ans


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
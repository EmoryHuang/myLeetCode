'''
Descroption: LeetCode 478. 在圆内随机生成点
Author: EmoryHuang
Date: 2022-06-05 10:48:04
Method:
极坐标变换，x = r * cos(theta)，y = r * sin(theta)，r，theta 相互独立
需要注意的是，随机一个离圆心的距离 + 角度，这是「距离圆心不同距离的每个圆环」的概率
而不是「圆内的均匀分布」，具体来说，可以计算概率密度函数来证明
实际上，可以随机 [0, r^2] 然后在开方，得到一个离圆心的距离
'''


class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x = x_center
        self.y = y_center

    def randPoint(self) -> List[float]:
        theta = random.uniform(0.0, math.pi * 2)
        r = sqrt(random.uniform(0.0, self.radius * self.radius))
        return [self.x + r * cos(theta), self.y + r * sin(theta)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()

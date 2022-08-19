'''
Descroption: LeetCode 478. ��Բ��������ɵ�
Author: EmoryHuang
Date: 2022-06-05 10:48:04
Method:
������任��x = r * cos(theta)��y = r * sin(theta)��r��theta �໥����
��Ҫע����ǣ����һ����Բ�ĵľ��� + �Ƕȣ����ǡ�����Բ�Ĳ�ͬ�����ÿ��Բ�����ĸ���
�����ǡ�Բ�ڵľ��ȷֲ�����������˵�����Լ�������ܶȺ�����֤��
ʵ���ϣ�������� [0, r^2] Ȼ���ڿ������õ�һ����Բ�ĵľ���
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

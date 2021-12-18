'''
Descroption: LeetCode 1610. 可见点的最大数目
Author: EmoryHuang
Date: 2021-12-16 08:58:05
Method:
数学 + 滑动窗口
使用公式计算两向量之间的夹角（point 与 location, x轴的单位向量）
theta = atan2(p[1] - location[1], p[0] - location[0])
然后按弧度进行排序，使用滑动窗口统计视角内可见点的最大数目
注意和 location 重合的点
'''


class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int,
                      location: List[int]) -> int:
        # 计算弧度
        same = 0
        angle_point = []
        for p in points:
            if p == location:
                same += 1
            else:
                angle_point.append(math.atan2(p[1] - location[1], p[0] - location[0]))
        angle_point.sort()
        # 防止反转
        n = len(angle_point)
        angle_point += [deg + 2 * math.pi for deg in angle_point]

        ans, r = 0, 0
        for i in range(n):
            # 找到视野范围内的点
            while r < n * 2 and angle_point[r] - angle_point[i] <= angle * math.pi / 180:
                r += 1
            ans = max(ans, r - i)
        return ans + same
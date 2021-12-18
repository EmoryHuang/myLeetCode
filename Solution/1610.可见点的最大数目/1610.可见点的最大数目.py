'''
Descroption: LeetCode 1610. �ɼ���������Ŀ
Author: EmoryHuang
Date: 2021-12-16 08:58:05
Method:
��ѧ + ��������
ʹ�ù�ʽ����������֮��ļнǣ�point �� location, x��ĵ�λ������
theta = atan2(p[1] - location[1], p[0] - location[0])
Ȼ�󰴻��Ƚ�������ʹ�û�������ͳ���ӽ��ڿɼ���������Ŀ
ע��� location �غϵĵ�
'''


class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int,
                      location: List[int]) -> int:
        # ���㻡��
        same = 0
        angle_point = []
        for p in points:
            if p == location:
                same += 1
            else:
                angle_point.append(math.atan2(p[1] - location[1], p[0] - location[0]))
        angle_point.sort()
        # ��ֹ��ת
        n = len(angle_point)
        angle_point += [deg + 2 * math.pi for deg in angle_point]

        ans, r = 0, 0
        for i in range(n):
            # �ҵ���Ұ��Χ�ڵĵ�
            while r < n * 2 and angle_point[r] - angle_point[i] <= angle * math.pi / 180:
                r += 1
            ans = max(ans, r - i)
        return ans + same
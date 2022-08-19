'''
Descroption: LeetCode 1401. Բ�;����Ƿ����ص�
Author: EmoryHuang
Date: 2021-06-05 14:25:00
����˼·:
��������, �ж�Բ�ĵ�λ�����ĸ�����
'''


class Solution:
    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # �ж�Բ���Ƿ��ھ�����
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        # Բ��λ�ھ��ε����������ĸ�����
        elif x_center > x2 and y1 <= y_center <= y2:  # ��
            return radius >= x_center - x2
        elif y_center < y1 and x1 <= x_center <= x2:  # ��
            return radius >= y1 - y_center
        elif x_center < x1 and y1 <= y_center <= y2:  # ��
            return radius >= x1 - x_center
        elif y_center > y2 and x1 <= x_center <= x2:  # ��
            return radius >= y_center - y2
        else:
            # �жϾ��ε��ĸ������Ƿ���Բ���ڲ�
            return min((x1 - x_center) ** 2 + (y2 - y_center) ** 2,
                       (x2 - x_center) ** 2 + (y2 - y_center) ** 2,
                       (x2 - x_center) ** 2 + (y1 - y_center) ** 2,
                       (x1 - x_center) ** 2 + (y1 - y_center) ** 2) <= radius ** 2
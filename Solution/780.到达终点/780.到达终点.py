'''
Descroption: LeetCode 780. �����յ�
Author: EmoryHuang
Date: 2022-04-09 08:55:53
Method:
���յ㷴����������
ת���Ǵӵ� (x, y) ת���� (x, x+y) ���� (x+y, y)
�������ʱ, ÿ��ʹ�� tx, ty �еĽϴ�ֵ��ȥ��Сֵ, ʹ�ò��ϱƽ����

Ϊ�˿��ٱƽ�, ����ÿ�ν��ϴ�ֵһ���Լ�ȥ�౶�Ľ�Сֵ, �Ӷ����ٵ�������
'''


class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > 0 and ty > 0:
            if tx == sx and ty == sy:
                return True
            if tx > ty:
                tx -= ty * max((tx - sx) // ty, 1)
            else:
                ty -= tx * max((ty - sy) // tx, 1)
        return False
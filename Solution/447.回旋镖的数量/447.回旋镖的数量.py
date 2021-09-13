'''
Descroption: LeetCode 447. �����ڵ�����
Author: EmoryHuang
Date: 2021-09-13 11:03:11
Method:
���� + ��ϣ��
������ǰ�㵽������ľ��룬���ù�ϣ���¼������ִ���
��ÿ��������ִ��� n ��ѡ������������Ϊ����������
�� A(n, 2) = n * (n - 1)
'''


class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for a, b in points:
            hash = defaultdict(int)
            # ������ǰ�㵽������ľ���
            for c, d in points:
                dis = (a - c)**2 + (b - d)**2
                hash[dis] += 1
            # ��ÿ��������ִ��� n ��ѡ��������
            # �� A(n, 2) = n * (n - 1)
            for n in hash.values():
                ans += n * (n - 1)
        return ans

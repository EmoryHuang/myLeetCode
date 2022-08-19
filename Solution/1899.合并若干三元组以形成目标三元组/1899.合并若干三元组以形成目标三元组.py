'''
Descroption: LeetCode 1899. �ϲ�������Ԫ�����γ�Ŀ����Ԫ��
Author: EmoryHuang
Date: 2021-11-04 20:41:50
Method:
̰��
��������ÿ������С�� target ����ȫ�����кϲ����Ƚ��Ƿ��� target ��ͬ
'''


class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        cur = [0] * 3
        for a, b, c in triplets:
            if a <= target[0] and b <= target[1] and c <= target[2]:
                cur[0] = max(cur[0], a)
                cur[1] = max(cur[1], b)
                cur[2] = max(cur[2], c)
        return cur == target
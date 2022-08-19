'''
Descroption: LeetCode 275. H ָ�� II
Author: EmoryHuang
Date: 2021-07-12 20:56:30
����˼·:
���ַ�Ѱ���Ҷ˵�
'''


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l, r = 0, len(citations)
        while l < r:
            mid = l + (r - l + 1) // 2
            # ������ mid ���������������
            if citations[len(citations) - mid] >= mid:
                l = mid
            else:
                r = mid - 1
        return l
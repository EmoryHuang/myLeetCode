'''
Descroption: LeetCode 1962. �Ƴ�ʯ��ʹ������С
Author: EmoryHuang
Date: 2021-10-21 09:16:30
Method:
�����
ά��һ������ѣ�ȡ�Ѷ�Ԫ�� / 2 ����ѣ��������Ԫ��֮��
'''


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = [-num for num in piles]
        heapq.heapify(heap)
        while k > 0:
            cur = -heapq.heappop(heap)
            heapq.heappush(heap, -cur // 2)
            k -= 1
        return -sum(heap)

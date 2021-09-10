'''
Descroption: LeetCode 1642. ���Ե������Զ����
Author: EmoryHuang
Date: 2021-07-24 14:35:07
Method:
ά��һ����С��
��gap������С�ѣ����Ƚ��������ڼ�����ĵط���С�������ש��
���ש��ĸ���С��0ʱ����
'''


class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        heap = []
        n = len(heights)
        for i in range(1, n):
            gap = heights[i] - heights[i - 1]
            # ֻ�����ϲ���Ҫ�õ�����
            if gap > 0:
                # ��gap������С��
                heapq.heappush(heap, gap)
                # ���Ƚ��������ڼ�����ĵط�
                if len(heap) > ladders:
                    # С�������ש��
                    bricks -= heapq.heappop(heap)
                    # ש��ĸ���С��i0ʱ����
                    if bricks < 0:
                        return i - 1
        return n - 1

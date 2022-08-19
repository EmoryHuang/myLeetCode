'''
Descroption: LeetCode 373. ���Һ���С��K������
Author: EmoryHuang
Date: 2021-08-24 15:38:50
Method:
ά��һ������ѣ�����������Ԫ��֮��
�����е�Ԫ���������� k����ô����ǰԪ����Ѷ�Ԫ�رȽ�
'''


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int],
                       k: int) -> List[List[int]]:
        n1, n2 = len(nums1), len(nums2)
        heap = []
        for i in range(min(n1, k)):
            for j in range(min(n2, k)):
                if len(heap) < k:
                    heapq.heappush(heap, (-nums1[i] - nums2[j], nums1[i], nums2[j]))
                elif -heap[0][0] > nums1[i] + nums2[j]:
                    heapq.heappushpop(heap, (-nums1[i] - nums2[j], nums1[i], nums2[j]))
        ans = []
        while heap:
            _, u, v = heapq.heappop(heap)
            ans.append([u, v])
        return ans
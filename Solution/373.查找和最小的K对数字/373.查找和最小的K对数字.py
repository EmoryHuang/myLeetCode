'''
Descroption: LeetCode 373. 查找和最小的K对数字
Author: EmoryHuang
Date: 2021-08-24 15:38:50
Method:
维护一个大根堆，遍历数组存放元素之和
若堆中的元素数量大于 k，那么将当前元素与堆顶元素比较
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
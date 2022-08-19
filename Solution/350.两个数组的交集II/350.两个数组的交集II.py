'''
Descroption: LeetCode 350. 两个数组的交集 II
Author: EmoryHuang
Date: 2021-06-11 16:49:00
解题思路:
与前一题不同的是，可以有重复元素
排序 + 双指针
先排序，然后使用双指针遍历数组，若元素相同则放入集合
否则将较小一方的指针后移
'''


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        unit = []
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                unit.append(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                i += 1
        return unit

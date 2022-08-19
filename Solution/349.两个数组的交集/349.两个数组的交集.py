'''
Descroption: LeetCode 349. 两个数组的交集
Author: EmoryHuang
Date: 2021-06-11 16:25:00
解题思路:
方法一：使用封装函数

方法二：排序 + 双指针
先排序，然后使用双指针遍历数组，若元素相同则放入集合
否则将较小一方的指针后移
'''


class Solution:
    # 方法一：使用封装函数
    # def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
    #     return list(set(nums1) & set(nums2))

    # 方法二：排序 + 双指针
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        unit = set()
        i, j = 0, 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                unit.add(nums1[i])
                i, j = i + 1, j + 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                i += 1
        return list(unit)

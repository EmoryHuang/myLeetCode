'''
Descroption: LeetCode 870. 优势洗牌
Author: EmoryHuang
Date: 2021-07-21 19:41:28
解题思路:
贪心思想，田忌赛马
二分法寻找左端点，在 nums1 中找到大于 nums2[i] 的最小值
若不存在，则返回 nums1 中的最小值
'''


class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        nums1.sort()
        for i in range(len(nums2)):
            # 二分法寻找左端点
            l, r = 0, len(nums1) - 1
            while l < r:
                mid = (l + r) >> 1
                if nums1[mid] > nums2[i]:
                    r = mid
                else:
                    l = mid + 1
            if nums1[l] > nums2[i]:
                # 找到大于 nums2[i] 的最小值
                ans.append(nums1[l])
                del nums1[l]
            else:
                # 若没有找到大于 nums2[i] 的最小值
                # 则返回 nums1 中的最小值
                ans.append(nums1[0])
                del nums1[0]
        return ans

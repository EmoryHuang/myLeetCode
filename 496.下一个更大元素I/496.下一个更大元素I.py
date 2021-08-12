'''
Descroption: LeetCode 496. 下一个更大元素 I
Author: EmoryHuang
Date: 2021-08-12 19:09:23
Method:
单调栈 + 哈希表
维护一个单调栈，统计 nums2 中当前字符右边更大的数组
然后遍历 nums1 同样是对应位置的比较
'''


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash = {}
        stack = []
        for num in nums2:
            # 维护一个单调栈
            while stack and stack[-1] < num:
                hash[stack.pop()] = num
            stack.append(num)
        return [hash.get(num, -1) for num in nums1]

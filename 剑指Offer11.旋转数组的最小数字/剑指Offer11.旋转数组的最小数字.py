'''
Descroption: 剑指 Offer 11. 旋转数组的最小数字
Author: EmoryHuang
Date: 2021-06-29 20:12:00
解题思路:
二分法
如果中间的元素比右边的元素小，那么满足，令 r = mid，因为 mid 可能是最小元素
如果中间的元素比右边的元素大，那么令 l = mid + 1，因为 mid 不可能是最小元素
如果中间的元素等于右边的元素，那么令 r--，减小范围
'''


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        l, r = 0, len(numbers) - 1
        while l < r:
            mid = l + (r - l) // 2
            if numbers[mid] < numbers[r]:
                r = mid
            elif numbers[mid] > numbers[r]:
                l = mid + 1
            else:
                r -= 1
        return numbers[l]

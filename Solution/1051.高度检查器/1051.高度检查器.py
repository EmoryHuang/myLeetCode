'''
Descroption: LeetCode 1051. 高度检查器
Author: EmoryHuang
Date: 2021-07-17 14:27:48
解题思路:
一个很简单的思想是将原数组进行排序，然后将排序后的数组与原数组进行比较
然后计数有多少个元素没到指定的位置

采用桶排序的思想可以避免排序，时间复杂度为O(n)
'''


class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        arr = [0] * 101
        # 使用 arr 记录每个元素的数量
        for height in heights:
            arr[height] += 1
        ans = j = 0
        for i in range(1, len(arr)):
            # 每次从桶中拿出一个数
            while arr[i] > 0:
                # 因为默认就是非递减的顺序，直接与 heights 比较
                if heights[j] != i:
                    ans += 1
                j += 1
                arr[i] -= 1
        return ans

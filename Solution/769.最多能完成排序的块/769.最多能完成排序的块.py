'''
Descroption: LeetCode 769. 最多能完成排序的块
Author: EmoryHuang
Date: 2022-10-13 09:07:35
Method:
贪心
由于按升序排序后，数字与其下标相同
那么可以遍历数组并维护当前最大值，最大值与当前下标相同时，则说明找到了正确位置
'''


class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ans, max_num = 0, -1
        for i, num in enumerate(arr):
            max_num = max(max_num, num)
            ans += 1 if max_num == i else 0
        return ans
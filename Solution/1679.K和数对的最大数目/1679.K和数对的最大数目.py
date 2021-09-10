'''
Descroption: LeetCode 1679. K 和数对的最大数目
Author: EmoryHuang
Date: 2021-07-20 20:51:09
解题思路:
遍历闭区间内的每一个整数，记录位于区间内的元素的数量
'''


class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        cnt = 0
        hash = defaultdict(int)
        for num in nums:
            # 如果没有对应的加数，记录 num
            if hash[k - num] == 0:
                hash[num] += 1
            # 如果有对应的加数，记录 k - num
            else:
                cnt += 1
                hash[k - num] -= 1
        return cnt

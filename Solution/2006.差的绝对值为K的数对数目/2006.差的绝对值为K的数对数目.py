'''
Descroption: LeetCode 2006. 差的绝对值为 K 的数对数目
Author: EmoryHuang
Date: 2021-10-08 19:19:55
Method:
哈希表记录之前的数据个数
'''


class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        hash = [0] * 101
        ans = 0
        for num in nums:
            if num - k >= 0:
                ans += hash[num - k]
            if num + k <= 100:
                ans += hash[num + k]
            hash[num] += 1
        return ans
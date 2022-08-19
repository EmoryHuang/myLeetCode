'''
Descroption: LeetCode 532. 数组中的 k-diff 数对
Author: EmoryHuang
Date: 2022-06-16 09:01:58
Method:
使用哈希表记录出现的数字
对于当前数字 num，如果 num - k 或 num + k 在哈希表中，则为 k-diff 数对
'''


class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        vis, ans = set(), set()
        for num in nums:
            if num - k in vis:
                ans.add(num - k)
            if num + k in vis:
                ans.add(num)
            vis.add(num)
        return len(ans)

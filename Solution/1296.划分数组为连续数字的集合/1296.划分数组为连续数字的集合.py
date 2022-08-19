'''
Descroption: LeetCode 1296. 划分数组为连续数字的集合
Author: EmoryHuang
Date: 2021-07-15 19:46:25
解题思路:
用哈希表记录各个元素的数量
对排序后的元素进行遍历，对于每个元素 num
若 num + i 的个数为0，则返回 false
'''


class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        if n % k != 0:
            return False
        nums.sort()
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
        for num in nums:
            if mp[num] == 0:
                continue
            for i in range(k):
                if num + i not in mp:
                    return False
                mp[num + i] -= 1
        return True

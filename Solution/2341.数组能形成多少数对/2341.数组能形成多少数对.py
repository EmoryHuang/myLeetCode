'''
Descroption: LeetCode 2341. 数组能形成多少数对
Author: EmoryHuang
Date: 2023-02-16 09:15:30
Method:
简单题，哈希表记录数字出现次数
'''


class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        ans = [0] * 2
        for k, v in cnt.items():
            ans[0] += v // 2
            ans[1] += v % 2
        return ans

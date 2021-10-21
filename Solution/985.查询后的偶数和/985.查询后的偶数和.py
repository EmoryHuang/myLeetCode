'''
Descroption: LeetCode 985. 查询后的偶数和
Author: EmoryHuang
Date: 2021-10-21 19:31:08
Method:
模拟
计算原数组偶数和 s，遍历查询
若修改前是偶数，则在 s 中减去
若修改后变成了偶数，则加上这个数
'''


class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        # 计算原数组偶数和
        s = sum([num for num in nums if num % 2 == 0])
        ans = []
        for val, idx in queries:
            # 若修改前是偶数，则在 s 中减去
            if nums[idx] % 2 == 0:
                s -= nums[idx]
            nums[idx] += val
            # 若修改后变成了偶数
            if nums[idx] % 2 == 0:
                s += nums[idx]
            ans.append(s)
        return ans
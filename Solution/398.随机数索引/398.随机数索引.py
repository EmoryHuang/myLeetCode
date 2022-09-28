'''
Descroption: LeetCode 398. 随机数索引
Author: EmoryHuang
Date: 2022-04-25 08:49:52
Method:
水塘抽样
当第 i 次遇到值为 target 的元素时, 随机选择区间 [0,i) 内的一个整数
如果其等于 0, 则将返回值置为该元素的下标, 否则返回值不变
'''


class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        ans, cnt = 0, 0
        for i, num in enumerate(self.nums):
            if num == target:
                cnt += 1
                if random.random() < 1 / cnt:
                    ans = i
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)

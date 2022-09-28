'''
Descroption: LeetCode 面试题 17.19. 消失的两个数字
Author: EmoryHuang
Date: 2022-09-26 10:10:42
Method:
对全部数组进行异或运算，根据异或运算规则，最后的得到的结果必然是剩下的两个数字的异或值
使用lowbit计算的到最右边1的位置l, 说明这两个数一个在l位为0, 另一个为1
'''

class Solution:

    def missingTwo(self, nums: List[int]) -> List[int]:
        n = len(nums) + 2
        vis = 0
        for num in nums:
            vis ^= num
        for i in range(1, n + 1):
            vis ^= i
        diff = vis & -vis
        a, b = 0, 0
        for num in nums:
            if diff & num:
                a ^= num
            else:
                b ^= num
        for i in range(1, n + 1):
            if diff & i:
                a ^= i
            else:
                b ^= i
        return [a, b]

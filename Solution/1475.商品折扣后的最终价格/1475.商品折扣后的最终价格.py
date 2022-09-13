'''
Descroption: LeetCode 1475. 商品折扣后的最终价格
Author: EmoryHuang
Date: 2022-09-01 09:02:30
Method:
单调栈
从后往前遍历，维护最小值
'''


class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stack, ans = [0], [0] * len(prices)
        for i in range(len(prices) - 1, -1, -1):
            p = prices[i]
            while len(stack) > 1 and stack[-1] > p:
                stack.pop()
            ans[i] = p - stack[-1]
            stack.append(p)
        return ans

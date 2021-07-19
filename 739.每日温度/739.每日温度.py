'''
Descroption: LeetCode 739. 每日温度
Author: EmoryHuang
Date: 2021-07-19 15:50:09
解题思路:
维护一个递减栈，存储元素位置
若当前元素大于栈顶元素，则找到了更高的温度，更新出栈元素对应的等待天数
'''


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        stack = []
        for i, num in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < num:
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return ans

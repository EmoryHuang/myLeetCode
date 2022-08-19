'''
Descroption: 剑指 Offer II 038. 每日温度
Author: EmoryHuang
Date: 2021-08-04 19:46:09
Method:
维护一个单调栈
遍历数组，若遇到比栈顶元素更大的元素，则更新出栈元素对应的等待天数
并将更大的这个元素入栈
'''


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        ans = [0] * len(temperatures)
        for i, t in enumerate(temperatures):
            # 维护递减栈
            while stack and temperatures[stack[-1]] < t:
                # 更新等待天数
                ans[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        return ans
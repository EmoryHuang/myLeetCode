'''
Descroption: LeetCode 636. 函数的独占时间
Author: EmoryHuang
Date: 2022-08-07 13:06:06
Method:
栈
当函数调用开始时，若栈非空，则停止当前函数，计算执行时间，然后将调用函数入栈。
当函数调用结束时，将栈顶元素弹出，并计算相应的执行时间，若栈非空，继续执行栈中函数。
'''


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans = [0] * n
        stack = []
        for log in logs:
            id, typ, time = log.split(':')
            id, time = int(id), int(time)
            if typ == 'start':
                if stack:
                    # 若栈非空，则更新上一个函数的时间
                    ans[stack[-1][0]] += time - stack[-1][1]
                    stack[-1][1] = time
                stack.append([id, time])
            else:
                i, t = stack.pop()
                ans[i] += time - t + 1
                if stack:
                    stack[-1][1] = time + 1
        return ans
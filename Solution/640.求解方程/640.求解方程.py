'''
Descroption: LeetCode 640. 求解方程
Author: EmoryHuang
Date: 2022-08-10 09:02:40
Method:
模拟
遍历字符串，将其转换为 k * x = val
'''


class Solution:
    def solveEquation(self, equation: str) -> str:
        factor = val = 0
        i, n, sign = 0, len(equation), 1
        while i < n:
            # 等号变号
            if equation[i] == '=':
                sign = -1
                i += 1
                continue

            # 加减号处理
            s = sign
            if equation[i] == '+':
                i += 1
            elif equation[i] == '-':
                s = -s
                i += 1

            # 数字处理
            num, flag = 0, False
            while i < n and equation[i].isdigit():
                flag = True
                num = num * 10 + int(equation[i])
                i += 1

            # 变量处理
            if i < n and equation[i] == 'x':
                factor += s * num if flag else s
                i += 1
            else:
                val += s * num
        if factor == 0:
            return "No solution" if val else "Infinite solutions"
        return "No solution" if val % factor else f"x={-val // factor}"
'''
Descroption: LeetCode 282. 给表达式添加运算符
Author: EmoryHuang
Date: 2021-10-16 09:13:42
Method:
回溯
使用回溯考虑所有可能的操作数，计算 '+', '-', '*'
计算乘法时，由于优先级的问题，需要记录上一步的操作数，使用 pre 记录
'''


class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(path: str, idx: int, cur: int, pre: int) -> None:
            if idx == len(num):
                if cur == target:
                    ans.append(path)
                return
            for i in range(idx, len(num)):
                # 数字不能以 0 开头
                if num[idx] == '0' and i > idx:
                    break
                # 遍历得到可能的数字
                c = num[idx:i + 1]
                if idx == 0:
                    dfs(path + c, i + 1, int(c), int(c))
                else:
                    dfs(path + '+' + c, i + 1, cur + int(c), int(c))
                    dfs(path + '-' + c, i + 1, cur - int(c), -int(c))
                    # 计算乘法时，由于优先级的问题，需要记录上一步的操作数，使用 pre 记录
                    dfs(path + '*' + c, i + 1, cur - pre + pre * int(c), pre * int(c))

        ans = []
        dfs('', 0, 0, 0)
        return ans

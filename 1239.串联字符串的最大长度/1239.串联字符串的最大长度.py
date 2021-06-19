'''
Descroption: LeetCode 1239. 串联字符串的最大长度
Author: EmoryHuang
Date: 2021-06-19 13:47:00
解题思路:
用collect保存此前找到的可行解
然后看当前字符串是否可以和collect中的拼接字符串继续拼接
'''


class Solution:
    def maxLength(self, arr: List[str]) -> int:
        collect = ['']
        ans = 0
        for s in arr:
            add = []
            for c in collect:
                t = c+s
                if len(t) == len(set(t)):
                    add.append(t)
                    ans = max(len(t), ans)
            collect.extend(add)
        return ans

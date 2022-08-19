'''
Descroption: LeetCode 1807. 替换字符串中的括号内容
Author: EmoryHuang
Date: 2021-09-24 18:59:30
Method:
哈希表
遍历字符串，若遇到括号则读取 key 并获取对应的 value
若 key 不存在则填 ?
'''


class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        hash = defaultdict(str)
        for key, val in knowledge:
            hash[key] = val
        ans, i = [], 0
        while i < len(s):
            key = ''
            if s[i] == '(':
                i += 1
                while s[i] != ')':
                    key += s[i]
                    i += 1
                if key in hash:
                    ans.append(hash[key])
                else:
                    ans.append('?')
            elif s[i] != ')':
                ans.append(s[i])
            i += 1
        return ''.join(ans)

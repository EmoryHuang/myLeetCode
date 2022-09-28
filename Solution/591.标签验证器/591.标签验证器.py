'''
Descroption: LeetCode 591. 标签验证器
Author: EmoryHuang
Date: 2022-05-02 11:01:15
Method:
正则表达式偷懒
'''

class Solution:
    def isValid(self, code: str) -> bool:
        code = re.sub(r'<!\[CDATA\[.*?\]\]>|t', '-', code)
        prev = None
        while code != prev:
            prev = code
            code = re.sub(r'<([A-Z]{1,9})>[^<]*</\1>', 't', code)
        return code == 't'
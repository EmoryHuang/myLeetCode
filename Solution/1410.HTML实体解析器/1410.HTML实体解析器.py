'''
Descroption: LeetCode 1410. HTML 实体解析器
Author: EmoryHuang
Date: 2021-08-17 18:39:55
Method:
replace替换即可，注意 & 放在最后替换
'''


class Solution:
    def entityParser(self, text: str) -> str:
        return text.replace('&quot;', '"').replace('&apos;', '\'').replace(
            '&gt;', '>').replace('&lt;', '<').replace('&frasl;', '/').replace('&amp;', '&')

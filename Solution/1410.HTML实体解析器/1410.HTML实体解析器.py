'''
Descroption: LeetCode 1410. HTML ʵ�������
Author: EmoryHuang
Date: 2021-08-17 18:39:55
Method:
replace�滻���ɣ�ע�� & ��������滻
'''


class Solution:
    def entityParser(self, text: str) -> str:
        return text.replace('&quot;', '"').replace('&apos;', '\'').replace(
            '&gt;', '>').replace('&lt;', '<').replace('&frasl;', '/').replace('&amp;', '&')

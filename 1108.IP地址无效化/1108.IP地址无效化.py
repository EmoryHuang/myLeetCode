'''
Descroption: LeetCode 1108. IP ��ַ��Ч��
Author: EmoryHuang
Date: 2021-08-08 14:17:42
Method:
replace�滻
'''


class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')

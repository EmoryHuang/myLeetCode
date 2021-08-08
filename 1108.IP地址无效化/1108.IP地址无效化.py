'''
Descroption: LeetCode 1108. IP 地址无效化
Author: EmoryHuang
Date: 2021-08-08 14:17:42
Method:
replace替换
'''


class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')

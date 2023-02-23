'''
Descroption: LeetCode 2283. 判断一个数的数字计数是否等于数位的值
Author: EmoryHuang
Date: 2023-01-11 09:06:12
Method:
哈希表记录数字出现次数
'''


class Solution:
    def digitCount(self, num: str) -> bool:
        h = Counter(num)
        for idx, v in enumerate(num):
            if h[str(idx)] != int(v):
                return False
        return True

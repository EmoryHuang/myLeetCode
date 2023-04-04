'''
Descroption: LeetCode 831. 隐藏个人信息
Author: EmoryHuang
Date: 2023-04-01 09:46:55
Method:
根据题意来即可
'''


class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            name, domain = s.split('@')
            hid_name = name.lower()[0] + '*****' + name.lower()[-1]
            return '@'.join([hid_name, domain.lower()])
        else:
            nums = [c for c in s if c.isdigit()]
            if len(nums) > 10:
                code = '+' + '*' * (len(nums) - 10)
                return '-'.join([code, '***', '***', ''.join(nums[-4:])])
            return '-'.join(['***', '***', ''.join(nums[-4:])])

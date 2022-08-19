'''
Descroption: LeetCode 468. 验证IP地址
Author: EmoryHuang
Date: 2022-05-29 10:16:57
Method:
检查IP地址是否合法
IPv4: '.'分割共 4 段，每段均为数字，最大值为 255，不包含前导 0
IPv6: ':'分割共 8 段，每段均为数字字母，最大值为 ffff
'''


class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def checkIPv4(queryIP):
            if queryIP.count('.') != 3:
                return False
            for i in queryIP.split('.'):
                if not i.isdigit() or (i[0] == '0' and len(i) > 1) or int(i) > 255:
                    return False
            return True

        def checkIPv6(queryIP):
            if queryIP.count(':') != 7:
                return False
            for i in queryIP.split(':'):
                check = lambda p: 'a' <= p <= 'f' or 'A' <= p <= 'F' or p.isdigit()
                if not all(check(p) for p in i) or len(i) > 4 or len(i) == 0 or int(i, 16) > 65535:
                    return False
            return True

        if checkIPv4(queryIP):
            return 'IPv4'
        elif checkIPv6(queryIP):
            return 'IPv6'
        else:
            return 'Neither'

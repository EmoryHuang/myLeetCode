'''
Descroption: LeetCode 468. ��֤IP��ַ
Author: EmoryHuang
Date: 2022-05-29 10:16:57
Method:
���IP��ַ�Ƿ�Ϸ�
IPv4: '.'�ָ 4 �Σ�ÿ�ξ�Ϊ���֣����ֵΪ 255��������ǰ�� 0
IPv6: ':'�ָ 8 �Σ�ÿ�ξ�Ϊ������ĸ�����ֵΪ ffff
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

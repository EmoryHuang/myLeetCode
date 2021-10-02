'''
Descroption: LeetCode 405. ����ת��Ϊʮ��������
Author: EmoryHuang
Date: 2021-10-02 16:42:47
Method:
λ����
���� num��ÿ4λ��Ӧһ��ʮ������λ
ʹ��0xf(00...01111b)��ȡnum�ĵ�4λ
'''


class Solution:
    def toHex(self, num: int) -> str:
        if num == 0: return '0'
        hash = '0123456789abcdef'
        ans = ''
        while num and len(ans) < 8:
            # ʹ��0xf(00...01111b)��ȡnum�ĵ�4λ
            ans = hash[0xf & num] + ans
            num >>= 4
        return ans

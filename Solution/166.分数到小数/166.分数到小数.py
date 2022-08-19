'''
Descroption: LeetCode 166. ������С��
Author: EmoryHuang
Date: 2021-10-03 20:32:35
Method:
ģ��
ʹ�ù�ϣ���¼ĳ������������ʲôλ�ó��ֹ���
һ��������ͬ�������򽫡�����λ�á�������ǰ��β��֮����ַ����ٳ���
'''


class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0:
            return str(numerator // denominator)
        ans = ''
        if numerator * denominator < 0:
            ans += '-'
        a, b = abs(numerator), abs(denominator)
        # ��¼С����֮ǰ�Ĳ���
        ans += str(a // b) + '.'
        hash = defaultdict(int)
        a %= b
        while a:
            # ��ϣ���¼��ǰ�������ֵ�λ��
            hash[a] = len(ans)
            a *= 10
            ans += str(a // b)
            a %= b
            if a in hash:
                return '{}({})'.format(ans[:hash[a]], ans[hash[a]:])
        return ans

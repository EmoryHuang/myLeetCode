'''
Descroption: LeetCode 166. 分数到小数
Author: EmoryHuang
Date: 2021-10-03 20:32:35
Method:
模拟
使用哈希表记录某个余数最早在什么位置出现过，
一旦出现相同余数，则将「出现位置」到「当前结尾」之间的字符串抠出来
'''


class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator % denominator == 0:
            return str(numerator // denominator)
        ans = ''
        if numerator * denominator < 0:
            ans += '-'
        a, b = abs(numerator), abs(denominator)
        # 记录小数点之前的部分
        ans += str(a // b) + '.'
        hash = defaultdict(int)
        a %= b
        while a:
            # 哈希表记录当前余数出现的位置
            hash[a] = len(ans)
            a *= 10
            ans += str(a // b)
            a %= b
            if a in hash:
                return '{}({})'.format(ans[:hash[a]], ans[hash[a]:])
        return ans

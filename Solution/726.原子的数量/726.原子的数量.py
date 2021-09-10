'''
Descroption: LeetCode 726. 原子的数量
Author: EmoryHuang
Date: 2021-07-05 21:58:48
解题思路:
反向遍历字符串
若读到数字则记录，若读到字母则记录
若读到 ) 则将其左边的数字作为倍数，并更新总倍数
若读到 ( 则将对应 ) 的倍数还原
若读到大写字母，则反转字符串，并将 str 和 num 放入 map
'''


class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # s 记录字符，num 记录数字，muls记录总的倍数
        s = num = ""
        mp, hash = defaultdict(int), []
        muls = 1
        # 从后向前遍历字符串
        for c in formula[::-1]:
            # 如果是数字，则记录
            if c.isdigit():
                num = c + num
            elif c == ')':
                # 若 num 为空，则说明括号右边没有数字，则倍数为 1
                # 否则倍数为 num
                mul = 1 if num == "" else int(num)
                num = ""  # 重新记录 num
                muls *= mul  # 更新总的倍数
                hash.append(mul)
            elif c == '(':
                muls //= hash.pop()  # 更新总的倍数
            else:
                s += c
                # 若读到大写字母，则反转字符串，并加入 map
                if c.isupper():
                    if num == "":
                        mp[s[::-1]] += muls
                    else:
                        mp[s[::-1]] += int(num) * muls
                    s = num = ""
        return "".join(key if mp[key] == 1 else key + str(mp[key]) for key in sorted(mp.keys()))

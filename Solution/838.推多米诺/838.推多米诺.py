'''
Descroption: LeetCode 838. 推多米诺
Author: EmoryHuang
Date: 2022-02-21 09:01:19
Method:
双指针
找到一段连续的未被施加力的区间，通过左右两边的方向来确定该区间的倒向
left 和 right 表示改区间左右两边推倒的方向
方向相同，则往一个方向倒；方向相对，向中间倒
'''


class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        d = list(dominoes)
        # left 和 right 表示推倒的方向
        n, i, left = len(dominoes), 0, 'L'
        while i < len(dominoes):
            j = i
            # 找到一段连续的未被施加力的区间
            while j < n and dominoes[j] == '.':
                j += 1
            right = d[j] if j < n else 'R'
            if left == right:
                # 方向相同，往一个方向倒
                while i < j:
                    d[i] = right
                    i += 1
            elif left == 'R' and right == 'L':
                # 方向相对，向中间倒
                k = j - 1
                while i < k:
                    d[i] = 'R'
                    d[k] = 'L'
                    i += 1
                    k -= 1
            left = right
            i = j + 1
        return ''.join(d)

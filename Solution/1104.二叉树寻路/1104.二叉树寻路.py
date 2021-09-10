'''
Descroption: LeetCode 1104. 二叉树寻路
Author: EmoryHuang
Date: 2021-07-29 13:34:27
Method:
数学
若为偶数行，则将从左到右与从右到左进行转换
label = 2^(i - 1) + 2^(i) - 1 - label
'''


class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans = []
        row, start = 1, 1
        # row 表示 label 所在行
        # start 表示 label 所在行的最小数字
        while start * 2 <= label:
            row += 1
            start *= 2
        # 将 label 表示为从左到右的标号
        # 2^(i - 1) + 2^(i) - 1 - label
        if row % 2 == 0:
            label = (1 << row - 1) + (1 << row) - 1 - label
        while row:
            # 若为偶数行则表示为从右到左的标号
            if row % 2 == 0:
                ans.append((1 << row - 1) + (1 << row) - 1 - label)
            else:
                ans.append(label)
            row -= 1
            # 更新为父节点
            label >>= 1
        return ans[::-1]

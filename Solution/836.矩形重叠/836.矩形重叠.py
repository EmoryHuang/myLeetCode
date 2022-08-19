'''
Descroption: LeetCode 836. 矩形重叠
Author: EmoryHuang
Date: 2021-06-19 14:14:00
解题思路:
简单题，排除不相交的情况即可
还需要判断，是不是一个矩形
'''


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # 判断是不是矩形
        if rec1[0] == rec1[2] or rec1[1] == rec1[3] or rec2[0] == rec2[2] or rec2[1] == rec2[3]:
            return False
        # 判断位置
        if rec2[1] >= rec1[3] or rec1[1] >= rec2[3]:
            return False
        if rec1[0] >= rec2[2] or rec1[2] <= rec2[0]:
            return False
        return True

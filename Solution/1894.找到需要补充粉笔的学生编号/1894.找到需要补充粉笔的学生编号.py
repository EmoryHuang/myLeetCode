'''
Descroption: LeetCode 1894. 找到需要补充粉笔的学生编号
Author: EmoryHuang
Date: 2021-09-10 14:51:36
Method:
数学
求和，取余，找到n轮后剩下的数量，然后再遍历一次，找到需要补充的位置
'''


class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        cnt = k % sum(chalk)
        for i, num in enumerate(chalk):
            if cnt < num:
                return i
            cnt -= num
        return -1

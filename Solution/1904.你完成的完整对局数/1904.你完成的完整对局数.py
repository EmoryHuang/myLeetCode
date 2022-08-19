'''
Descroption: LeetCode 1904. 你完成的完整对局数
Author: EmoryHuang
Date: 2021-11-06 15:42:30
Method:
简单题，将时间转换为分钟
考虑结束时间前可以结束的最后一个对局或是开始时间的第一个对局
然后计算可以完成的完整对局数
'''


class Solution:
    def numberOfRounds(self, startTime: str, finishTime: str) -> int:
        sh, sm = startTime.split(':')
        fh, fm = finishTime.split(':')
        start = int(sh) * 60 + int(sm)
        end = int(fh) * 60 + int(fm)
        # 第二天
        if start > end:
            end += 24 * 60
        # 结束时间前可以结束的最后一个对局
        end = end // 15 * 15
        return max(0, (end - start)) // 15

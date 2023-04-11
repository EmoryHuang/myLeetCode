'''
Descroption: LeetCode 1041. 困于环中的机器人
Author: EmoryHuang
Date: 2023-04-11 09:29:47
Method:
模拟
一轮后不朝北或者回到原点都会陷入循环
'''


class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        X = [0, 1, 0, -1]
        Y = [1, 0, -1, 0]
        flag = 0
        x, y = 0, 0
        for v in instructions:
            if v == 'G':
                x += X[flag]
                y += Y[flag]
            elif v == 'L':
                flag = (flag - 1) % 4
            elif v == 'R':
                flag = (flag + 1) % 4
        return flag != 0 or (x == 0 and y == 0)

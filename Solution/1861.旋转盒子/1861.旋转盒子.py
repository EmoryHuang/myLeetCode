'''
Descroption: LeetCode 1861. 旋转盒子
Author: EmoryHuang
Date: 2021-10-22 15:15:43
Method:
模拟
由于石头的水平位置不会发生改变，因此可以遍历每行单独调整
对于每行，从后往前进行遍历，并且更新底部位置，将石头更新到底部
'''


class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])
        for i in range(m):
            # bottom 记录底部位置
            bottom = n
            for j in range(n - 1, -1, -1):
                if box[i][j] == '*':
                    # 如果是固定障碍物，则更新底部位置
                    bottom = j
                elif box[i][j] == '#':
                    # 如果是石头
                    bottom -= 1
                    box[i][j], box[i][bottom] = box[i][bottom], box[i][j]
        # 顺时针旋转 90 度
        return list(map(list, zip(*box[::-1])))
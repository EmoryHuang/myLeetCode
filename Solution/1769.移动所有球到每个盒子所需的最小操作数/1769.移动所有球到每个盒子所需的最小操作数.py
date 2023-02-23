'''
Descroption: LeetCode 1769. 移动所有球到每个盒子所需的最小操作数
Author: EmoryHuang
Date: 2022-12-02 09:11:15
Method:
遍历数组，依次处理每个盒子的移动情况
'''


class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        res = []
        for i in range(len(boxes)):
            s = sum(abs(j - i) for j, c in enumerate(boxes) if c == '1')
            res.append(s)
        return res

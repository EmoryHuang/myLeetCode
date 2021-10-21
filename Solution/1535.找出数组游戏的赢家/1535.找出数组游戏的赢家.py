'''
Descroption: LeetCode 1535. 找出数组游戏的赢家
Author: EmoryHuang
Date: 2021-10-21 19:54:19
Method:
模拟
一轮结束之后，在首位的必定是数组的最大值
'''


class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        cur, cnt = arr[0], 0
        for num in arr[1:]:
            if num > cur:
                cur = num
                cnt = 1
            else:
                cnt += 1
            if cnt == k:
                return cur
        return cur
'''
Descroption: LeetCode 1823. 找出游戏的获胜者
Author: EmoryHuang
Date: 2022-05-04 11:13:17
Method:
方法一: 队列模拟
在队列中放置 1 到 n 的玩家
每一轮游戏中，将队首元素取出并将该元素在队尾处重新加入队列，重复该操作 k - 1 次
第 k 次即为失败者，直达队列中只剩下一个玩家，即获胜者

方法二: 数学 + 模拟
每次往同一方向，以固定步长 k 进行消数
由于下一次操作的发起点为消除位置的下一个点
同时问题规模会从 n 变为 n - 1
因此有 f(n, k) = (f(n - 1, k) + k) % n
'''

from collections import defaultdict, deque, Counter
from typing import List
import re
import math
import heapq
import collections
import bisect
import random
import datetime


class Solution:
    # 方法一: 队列模拟
    # def findTheWinner(self, n: int, k: int) -> int:
    #     q = deque(range(1, n + 1))
    #     while len(q) > 1:
    #         for _ in range(k - 1):
    #             q.append(q.popleft())
    #         q.popleft()
    #     return q[0]

    # 方法二: 数学 + 模拟
    def findTheWinner(self, n: int, k: int) -> int:
        ans = 0
        for i in range(2, n + 1):
            ans = (ans + k) % i
        return ans + 1

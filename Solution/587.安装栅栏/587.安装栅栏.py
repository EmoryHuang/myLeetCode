'''
Descroption: LeetCode 587. 安装栅栏
Author: EmoryHuang
Date: 2022-04-23 10:08:17
Method:
方法一: Jarvis 算法
首先由一点必定在凸包的点开始，例如最左的一点 p。然后选择 q 点使得所有点都在 pq 的右方
以 q 为原点，重复这个步骤，依次找到凸包的 k 个点。

方法二: Andrew 算法
首先把所有点以横坐标为第一关键字，纵坐标为第二关键字排序。
使用栈来维护所有凸包上的点
求凸包的下半部分, 从前往后(寻找最右侧的点):
    若栈内元素少于 2 个，则直接将元素添加到栈中；
    若栈内元素不少于 2 个，考虑是否要将栈顶的边删掉
求凸包的上半部分, 从后往前(寻找最右侧的点):
    若栈内元素少于 m 个，则直接将元素添加到栈中；
    若栈内元素不少于 m 个，考虑是否要将栈顶的边删掉
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
    # 方法一: Jarvis 算法
    # def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
    #     def cross(p: List[int], q: List[int], r: List[int]) -> int:
    #         # 向量叉积 cross(p, q, r) = pq x qr
    #         # 若 pq x qr > 0, 则 r 在 pq 左侧
    #         # 若 pq x qr < 0, 则 r 在 pq 右侧
    #         # 若 pq x qr = 0, 则 r 在 pq 直线上
    #         return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])

    #     n = len(trees)
    #     if n < 4:
    #         return trees

    #     # 找到最左边的点(必定是凸包上的点)
    #     most_left = 0
    #     for i in range(n):
    #         if trees[i][0] < trees[most_left][0]:
    #             most_left = i
    #     ans = []
    #     vis = [False] * n
    #     p = most_left
    #     while True:
    #         q = (p + 1) % n
    #         # 寻找 pq 最右侧的点(最终 pq 为凸包的边)
    #         for r, tree in enumerate(trees):
    #             if cross(trees[p], trees[q], tree) < 0:
    #                 q = r
    #         # 是否存在点 i, 使得 p q i 在同一条直线上
    #         for i, b in enumerate(vis):
    #             if not b and i != p and i != q and \
    #                 cross(trees[p], trees[q], trees[i]) == 0:
    #                 ans.append(trees[i])
    #                 vis[i] = True
    #         if not vis[q]:
    #             ans.append(trees[q])
    #             vis[q] = True
    #         p = q
    #         if p == most_left:
    #             break
    #     return ans

    # 方法二: Andrew 算法
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        def cross(p: List[int], q: List[int], r: List[int]) -> int:
            # 向量叉积 cross(p, q, r) = pq x qr
            # 若 pq x qr > 0, 则 r 在 pq 左侧
            # 若 pq x qr < 0, 则 r 在 pq 右侧
            # 若 pq x qr = 0, 则 r 在 pq 直线上
            return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])

        n = len(trees)
        if n < 4:
            return trees

        # 按照 x 从小到大排序，如果 x 相同，则按照 y 从小到大排序
        trees.sort()

        # 使用栈来维护所有凸包上的点
        stack = [0]
        vis = [False] * n
        # 求凸包的下半部分, 从前往后(寻找最右侧的点)
        for i in range(1, n):
            # 若栈内元素少于 2 个，则直接将元素添加到栈中；
            # 若栈内元素不少于 2 个，考虑是否要将栈顶的边删掉
            while len(stack) > 1 and cross(trees[stack[-2]], trees[stack[-1]],
                                           trees[i]) < 0:
                vis[stack.pop()] = False
            vis[i] = True
            stack.append(i)

        # 求凸包的上半部分, 从后往前(寻找最右侧的点)
        m = len(stack)  # 下半部分的点数

        for i in range(n - 2, -1, -1):
            if vis[i]:  # 凸包的下半部分不能删去
                continue
            # 若栈内元素少于 m 个，则直接将元素添加到栈中；
            # 若栈内元素不少于 m 个，考虑是否要将栈顶的边删掉
            while len(stack) > m and cross(trees[stack[-2]], trees[stack[-1]],
                                           trees[i]) < 0:
                vis[stack.pop()] = False
            vis[i] = True
            stack.append(i)

        # 去掉第一个节点(头尾参与两次)
        stack.pop()
        return [trees[i] for i in stack]

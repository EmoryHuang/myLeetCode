'''
Descroption: LeetCode 773. 滑动谜题
Author: EmoryHuang
Date: 2021-06-26 13:43:00
解题思路:
BFS
将 board 看作字符串，我们需要得到的 target = "123450"
在当前状态 cur 中找出 0 所在的位置 x，对于每一个与 x 相邻的位置 y，
我们将 cur[x] 与 cur[y] 进行交换，得到下一个新的状态 next
并加入队列
'''


class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        neighbor = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
        target, start = "123450", ""  # 目标状态
        # 得到起始字符串
        for row in board:
            for s in row:
                start += str(s)
        if start == target:
            return 0
        q = deque([(start, 0)])  # 记录到当前状态需要 step 步
        vis = {start}  # 记录当前字符串是否访问
        while q:
            cur, step = q.popleft()
            if cur == target:  # 达到目标状态
                return step
            x = cur.index('0')  # 找到 0 的位置 x
            for y in neighbor[x]:
                next = list(cur)
                next[y], next[x] = next[x], next[y]  # 交换
                next = "".join(next)
                if next not in vis:  # next 未访问
                    vis.add(next)
                    q.append((next, step + 1))
        return -1

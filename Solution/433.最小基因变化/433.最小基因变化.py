'''
Descroption: LeetCode 433. 最小基因变化
Author: EmoryHuang
Date: 2022-05-07 08:56:51
Method:
bfs
使用队列记录当前状态，以及步数
bfs 枚举所有可能的状态
'''


class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        if end not in bank:
            return -1
        # 记录每个字符可变换的字符
        change = {'A': 'CGT', 'C': 'AGT', 'G': 'ACT', 'T': 'ACG'}
        # 队列记录状态和步数
        q = deque([(start, 0)])
        # bfs
        while q:
            cur, step = q.popleft()
            if cur == end:
                return step
            # 枚举可变换的字符串
            for i in range(len(cur)):
                for j in change[cur[i]]:
                    next = cur[:i] + j + cur[i + 1:]
                    if next in bank:
                        q.append((next, step + 1))
                        bank.remove(next)
        return -1
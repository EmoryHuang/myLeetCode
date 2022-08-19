'''
Descroption: LCP 07. ������Ϣ
Author: EmoryHuang
Date: 2021-07-01 13:23:00
����˼·:
�����˼·���Ǽ򵥵ģ������ڽӾ���
�жϵ�ǰ�ڵ��Ƿ񵽴�Ŀ��ڵ㣬���Ҳ���Ϊ k
����һ��DFS
��������BFS
'''


class Solution:
    # ����һ��DFS
    # def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
    #     self.ans = 0
    #     map = collections.defaultdict(list)
    #     for p, q in relation:
    #         map[p].append(q)

    #     def dfs(cur: int, step: int) -> None:
    #         if step == k:
    #             if cur == n - 1:
    #                 self.ans += 1
    #             return
    #         for next in map[cur]:
    #             dfs(next, step + 1)

    #     dfs(0, 0)
    #     return self.ans

    # ��������BFS
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        map = collections.defaultdict(list)
        ans = 0
        for p, q in relation:
            map[p].append(q)
        q = collections.deque()
        q.append([0, 0])  # ��¼��ǰ�ڵ��Լ����ﲽ��
        while q:
            cur, step = q.popleft()
            if step > k:
                break
            # �ҵ�һ��·��
            if cur == n - 1 and step == k:
                ans += 1
            for next in map[cur]:
                q.append([next, step + 1])
        return ans

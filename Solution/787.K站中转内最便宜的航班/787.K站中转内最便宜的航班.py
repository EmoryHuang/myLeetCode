'''
Descroption: LeetCode 787. K վ��ת������˵ĺ���
Author: EmoryHuang
Date: 2021-08-24 10:16:43
Method:
����һ���ѣ���ʱ��
���ݸ����ĺ�����Ϣ�����ڽӾ���ͬʱ���Ѵ洢·��
������С�ѣ�ÿ�ε�����ǰ�۸���С��·�ߣ�ֱ�������յ�

����������̬�滮
dp[i][k]��ʾ����k����תվ�󵽴�վi����ͷ���
״̬ת�Ʒ��̣�dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
'''


class Solution:
    # ����һ���ѣ���ʱ��
    # def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int,
    #                       k: int) -> int:
    #     if src == dst: return 0
    #     mp = defaultdict(list)
    #     for f, t, p in flights:
    #         mp[f].append([t, p])
    #     q = [(0, src, 0)]
    #     while q:
    #         total, u, step = heapq.heappop(q)
    #         # �����ת������������ k վ
    #         if step - 1 > k:
    #             continue
    #         # ����������յ�վ
    #         if u == dst:
    #             return total
    #         # ������ǰվ���ڽ�
    #         for v, p in mp[u]:
    #             heapq.heappush(q, (total + p, v, step + 1))
    #     return -1

    # ����������̬�滮
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int,
                          k: int) -> int:
        if src == dst: return 0
        # dp[i][k]��ʾ����k����תվ�󵽴�վi����ͷ���
        dp = [float('inf')] * n
        dp[src] = 0
        for i in range(k + 1):
            tmp = dp[:]
            for u, v, p in flights:
                # dp[v][k] = min(dp[v][k], dp[u][k - 1] + p);
                dp[v] = min(dp[v], tmp[u] + p)
        return dp[dst] if dp[dst] != float('inf') else -1

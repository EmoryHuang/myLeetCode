'''
Descroption: LeetCode 913. è������
Author: EmoryHuang
Date: 2022-01-04 12:37:51
Method:
��̬�滮 + ���仯����
dp[k][i][j]��ʾ������ k ���������λ��Ϊ i��èλ��Ϊ j�Ļ�ʤ���
0,1,2�ֱ����ƽ�֣�����Ӯ��èӮ
�����������ֺ�è���ֵ������������Ҫ����״̬
'''


class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(time, mouse, cat):
            if mouse == 0:
                return 1
            if mouse == cat:
                return 2
            if time >= 2 * n:
                return 0
            if not time % 2:  # ����
                ans = 2
                for next in graph[mouse]:
                    cur = dfs(time + 1, next, cat)
                    if cur == 1:
                        return 1
                    elif cur == 0:
                        ans = 0
                return ans
            else:  # è
                ans = 1
                for next in graph[cat]:
                    if next == 0:
                        continue
                    cur = dfs(time + 1, mouse, next)
                    if cur == 2:
                        return 2
                    elif cur == 0:
                        ans = 0
                return ans

        n = len(graph)
        # dp[k][i][j]��ʾ������ k ���������λ��Ϊ i��èλ��Ϊ j�Ļ�ʤ���
        # 0,1,2�ֱ����ƽ�֣�����Ӯ��èӮ
        # �����������ֺ�è���ֵ������������Ҫ����״̬
        return dfs(0, 1, 2)

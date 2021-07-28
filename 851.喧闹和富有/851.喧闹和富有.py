'''
Descroption: LeetCode 851. ���ֺ͸���
Author: EmoryHuang
Date: 2021-07-28 14:12:23
Method:
dfs
�洢 richer �еĸ�ԣ��ϵ
����ÿһ���ˣ��ҵ�������ԣ���ˣ�dfsѰ�ұ�����˸���ԣ����
��dfs�Ĺ����У�������С�İ���ֵ
'''


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        mp = [[] for _ in range(n)]
        # �洢��ԣ��ϵ
        for a, b in richer:
            mp[b].append(a)
        ans = [-1] * n

        def dfs(x: int) -> int:
            if ans[x] == -1:
                ans[x] = x
                # ����ÿһ����x����ԣ����
                for rich in mp[x]:
                    # dfs�ҵ�������˸���ԣ����
                    more_rich = dfs(rich)
                    # ������С�İ���ֵ
                    if quiet[more_rich] < quiet[ans[x]]:
                        ans[x] = more_rich
            return ans[x]

        for i in range(n):
            dfs(i)
        return ans
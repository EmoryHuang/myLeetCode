'''
Descroption: ��ָ Offer 38. �ַ���������
Author: EmoryHuang
Date: 2021-06-22 12:47:00
����˼·:
���ݷ���ʹ��setȥ��
'''


class Solution:
    def permutation(self, s: str) -> List[str]:
        ans = set()
        vis = [0] * len(s)

        def dfs(cur: str, ind: int) -> None:
            if ind == len(s):
                ans.add(cur)
                return
            for i in range(len(s)):
                if not vis[i]:
                    cur += s[i]
                    vis[i] = 1
                    dfs(cur, ind + 1)
                    cur = cur[:-1]
                    vis[i] = 0

        dfs("", 0)
        return list(ans)

'''
Descroption: LeetCode 851. 喧闹和富有
Author: EmoryHuang
Date: 2021-07-28 14:12:23
Method:
dfs
存储 richer 中的富裕关系
遍历每一个人，找到比它富裕的人，dfs寻找比这个人更富裕的人
在dfs的过程中，更新最小的安静值
'''


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        mp = [[] for _ in range(n)]
        # 存储富裕关系
        for a, b in richer:
            mp[b].append(a)
        ans = [-1] * n

        def dfs(x: int) -> int:
            if ans[x] == -1:
                ans[x] = x
                # 对于每一个比x更富裕的人
                for rich in mp[x]:
                    # dfs找到比这个人更富裕的人
                    more_rich = dfs(rich)
                    # 更新最小的安静值
                    if quiet[more_rich] < quiet[ans[x]]:
                        ans[x] = more_rich
            return ans[x]

        for i in range(n):
            dfs(i)
        return ans
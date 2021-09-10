'''
Descroption: 面试题 08.08. 有重复字符串的排列组合
Author: EmoryHuang
Date: 2021-07-19 15:26:09
解题思路:
DFS 回溯
使用 vis 记录元素是否访问，通过set去重
'''


class Solution:
    def permutation(self, S: str) -> List[str]:
        ans, word = set(), []
        vis = [0] * len(S)

        def dfs(vis):
            if len(word) == len(S):
                ans.add(''.join(word))
                return
            for i in range(len(S)):
                if not vis[i]:
                    word.append(S[i])
                    vis[i] = 1
                    dfs(vis)
                    word.pop()
                    vis[i] = 0

        dfs(vis)
        return list(ans)

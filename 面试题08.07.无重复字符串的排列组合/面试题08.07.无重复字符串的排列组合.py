'''
Descroption: ������ 08.07. ���ظ��ַ������������
Author: EmoryHuang
Date: 2021-07-19 15:21:55
����˼·:
DFS ����
ʹ�� vis ��¼Ԫ���Ƿ����
'''


class Solution:
    def permutation(self, S: str) -> List[str]:
        ans, word = [], []
        vis = [0] * len(S)

        def dfs(vis):
            if len(word) == len(S):
                ans.append(''.join(word))
                return
            for i in range(len(S)):
                if not vis[i]:
                    word.append(S[i])
                    vis[i] = 1
                    dfs(vis)
                    word.pop()
                    vis[i] = 0

        dfs(vis)
        return ans

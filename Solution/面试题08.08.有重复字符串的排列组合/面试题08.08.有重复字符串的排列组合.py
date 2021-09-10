'''
Descroption: ������ 08.08. ���ظ��ַ������������
Author: EmoryHuang
Date: 2021-07-19 15:26:09
����˼·:
DFS ����
ʹ�� vis ��¼Ԫ���Ƿ���ʣ�ͨ��setȥ��
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

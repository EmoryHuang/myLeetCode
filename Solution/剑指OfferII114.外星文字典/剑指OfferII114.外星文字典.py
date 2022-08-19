'''
Descroption: 剑指 Offer II 114. 外星文字典
Author: EmoryHuang
Date: 2022-05-31 09:40:17
Method:
拓扑排序 + BFS
将字典中的每个字母看成一个节点，字母之间的顺序关系看成有向边，进行建图
将所有入度为 0 的节点入队
使用 BFS 取出队列中的节点，将有连接的节点入度减 1，并将其入度为 0 的节点入队
如果有环，则返回空字符串
'''


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = defaultdict(list)
        indegree = defaultdict(int)
        for word in words:
            for ch in word:
                indegree[ch] = 0

        # 将字典中的每个字母看成一个节点，字母之间的顺序关系看成有向边
        for a, b in pairwise(words):
            for ca, cb in zip(a, b):
                if ca != cb:
                    g[ca].append(cb)
                    indegree[cb] += 1
                    break
            else:
                if len(a) > len(b):
                    return ""

        # 将所有入度为 0 的节点加入队列
        q = deque([k for k, v in indegree.items() if v == 0])
        res = ''

        while q:
            node = q.popleft()
            res += node
            # 更新入度
            for k in g[node]:
                indegree[k] -= 1
                if indegree[k] == 0:
                    q.append(k)
        # 如果有环，则返回空字符串
        return res if len(res) == len(indegree) else ''
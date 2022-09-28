'''
Descroption: LeetCode 854. 相似度为 K 的字符串
Author: EmoryHuang
Date: 2022-09-21 09:31:06
Method:
dfs + 剪枝
若s1和s2如果当前字符相同则继续向下搜索
否则遍历s2中后面的字符，直到找到相同的字符
到达末尾时停止，更新最小交换次数
'''


class Solution:

    def kSimilarity(self, s1: str, s2: str) -> int:

        def dfs(l1, l2, idx, cnt):
            # 停止更新最小交换次数
            if idx == len(l1):
                self.ans = min(self.ans, cnt)
            # 提前停止
            if cnt >= self.ans:
                return
            if l1[idx] == l2[idx]:
                # 如果当前字符相同则继续向下搜索
                dfs(l1, l2, idx + 1, cnt)
            else:
                # 否则遍历l2中后面的字符，直到找到相同的字符
                for i in range(idx, len(l2)):
                    if l2[i] == l1[idx]:
                        # 交换
                        l2[i], l2[idx] = l2[idx], l2[i]
                        dfs(l1, l2, idx + 1, cnt + 1)
                        l2[i], l2[idx] = l2[idx], l2[i]

        l1, l2 = list(s1), list(s2)
        self.ans = float('inf')
        dfs(l1, l2, 0, 0)
        return self.ans

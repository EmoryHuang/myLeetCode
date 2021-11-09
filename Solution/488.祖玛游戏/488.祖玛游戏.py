'''
Descroption: LeetCode 488. 祖玛游戏
Author: EmoryHuang
Date: 2021-11-09 16:00:38
Method:
dfs + 剪枝
爆搜，遍历手中球以及可以插入的每个位置，求最小的插入次数
使用一个 int 来记录 hand 的使用情况
'''


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def dfs(cur: str, use: int):
            if len(cur) == 0:
                return 0
            if cur in hash:
                return hash[cur]

            ans, n = float('inf'), len(cur)
            # 遍历所有可用字符
            for i in range(len(hand)):
                # 如果当前位已经使用过
                if (use >> i) & 1:
                    continue
                # 下一个状态
                next = (1 << i) | use
                # 遍历所有可插入位置
                for j in range(n + 1):
                    if 0 < j < n - 1 and cur[j] == cur[j - 1]:
                        continue
                    if 0 < j < n - 1 and cur[j] != hand[i]:
                        continue
                    s = cur[:j] + hand[i]
                    # 如果不是最后一个位置
                    if j != n:
                        s += cur[j:]
                    k = j
                    while 0 <= k < len(s):
                        l, r = k, k
                        # 从插入位置向左向右搜索连续 3 个的字符
                        while l >= 0 and s[l] == s[k]:
                            l -= 1
                        while r < len(s) and s[r] == s[k]:
                            r += 1
                        if r - l - 1 >= 3:
                            s = s[:l + 1] + s[r:]
                            k = l if l >= 0 else r
                        else:
                            break
                    ans = min(ans, dfs(s, next) + 1)
            hash[cur] = ans
            return ans

        hash = defaultdict(int)
        res = dfs(board, 1 << len(hand))
        if res == float('inf'):
            return -1
        return res

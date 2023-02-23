'''
Descroption: LeetCode 1687. 从仓库到码头运输箱子
Author: EmoryHuang
Date: 2022-12-05 10:04:10
Method:
动态规划 + 单调队列
dp[i] 表示把前 i 个箱子从仓库运送到相应码头的最少行程数
状态转移方程：dp[i] = min_{j \in [i-maxBoxes, i-1]} (dp[j] + sum_{k=j+1}^i cost(k))
'''


class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, maxBoxes: int,
                      maxWeight: int) -> int:
        n = len(boxes)
        # weight[i] 表示前 i 个箱子的重量
        # neg[i] 表示一次性运送前 i 个箱子需要的行程次数
        weight, neg = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            p, w = boxes[i]
            weight[i + 1] = weight[i] + w
            if i < n - 1:
                neg[i + 1] = neg[i] + (p != boxes[i + 1][0])
        # dp[i] 表示运送前 i 个箱子需要的最少行程次数
        dp = [0] * (n + 1)
        # 单调队列存储每次运送的箱子
        q = deque([0])
        for i in range(1, n + 1):
            # 超过重量或数量则窗口左边界右移
            while q and (i - q[0] > maxBoxes or weight[i] - weight[q[0]] > maxWeight):
                q.popleft()
            if q:
                dp[i] = neg[i - 1] + dp[q[0]] - neg[q[0]] + 2
            if i < n:
                while q and dp[q[-1]] - neg[q[-1]] >= dp[i] - neg[i]:
                    q.pop()
                q.append(i)
        return dp[n]
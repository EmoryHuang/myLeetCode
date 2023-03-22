'''
Descroption: LeetCode 1626. 无矛盾的最佳球队
Author: EmoryHuang
Date: 2023-03-22 14:27:01
Method:
动态规划
将所有队员按照分数升序进行排序，分数相同时，则按照年龄升序进行排序
'''


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        # 按分数从小到大排序
        people = sorted(zip(scores, ages))
        dp = [0] * len(scores)
        ans = 0
        for i in range(len(scores)):
            for j in range(i):
                if people[i][1] >= people[j][1]:
                    dp[i] = max(dp[i], dp[j])
            dp[i] += people[i][0]
            ans = max(ans, dp[i])
        return ans
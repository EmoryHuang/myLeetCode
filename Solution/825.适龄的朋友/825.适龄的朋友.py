'''
Descroption: LeetCode 825. 适龄的朋友
Author: EmoryHuang
Date: 2021-08-19 15:12:55
Method:
哈希表计数
对于每个年龄，如果满足条件，就将 cntA * cntB 加入 ans
当年龄相同时，记录 cntA * (cntB - 1)
'''


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        hash = [0] * 121
        for age in ages:
            hash[age] += 1
        ans = 0
        for ageA, cntA in enumerate(hash):
            for ageB, cntB in enumerate(hash):
                if ageB <= 0.5 * ageA + 7: continue
                if ageB > ageA: continue
                if ageA < 100 < ageB: continue
                ans += cntA * cntB
                if ageA == ageB:
                    ans -= cntA
        return ans
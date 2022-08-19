'''
Descroption: LeetCode 825. ���������
Author: EmoryHuang
Date: 2021-08-19 15:12:55
Method:
��ϣ�����
����ÿ�����䣬��������������ͽ� cntA * cntB ���� ans
��������ͬʱ����¼ cntA * (cntB - 1)
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
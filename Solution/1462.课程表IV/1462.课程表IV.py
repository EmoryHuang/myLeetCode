'''
Descroption: LeetCode 1462. 课程表 IV
Author: EmoryHuang
Date: 2021-07-30 19:16:48
Method:
floyd算法判断两个点之间是否存在路径
'''


class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]],
                            queries: List[List[int]]) -> List[bool]:
        ans = []
        mp = [[False] * numCourses for _ in range(numCourses)]
        for r, c in prerequisites:
            mp[r][c] = True
        for k in range(numCourses):
            for i in range(numCourses):
                for j in range(numCourses):
                    if mp[i][k] and mp[k][j]:
                        mp[i][j] = True
        for r, c in queries:
            ans.append(mp[r][c])
        return ans

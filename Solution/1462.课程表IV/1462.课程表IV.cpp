/*
 * @Descroption: LeetCode 1462. 课程表 IV
 * @Author: EmoryHuang
 * @Date: 2021-07-30 19:19:57
 * @Method:
 * floyd算法判断两个点之间是否存在路径
 */

class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<bool>> mp(numCourses, vector<bool>(numCourses));
        for (auto pre : prerequisites) mp[pre[0]][pre[1]] = true;
        for (int k = 0; k < numCourses; k++)
            for (int i = 0; i < numCourses; i++)
                for (int j = 0; j < numCourses; j++)
                    if (mp[i][k] && mp[k][j]) mp[i][j] = true;
        for (auto q : queries) ans.push_back(mp[q[0]][q[1]]);
        return ans;
    }
};
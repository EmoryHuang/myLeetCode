/*
 * @Descroption: LeetCode 1791. �ҳ�����ͼ�����Ľڵ�
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:23:42
 * @Method:
 * ���⣬Ѱ�������ߵ���ͬ�ڵ�
 */

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};
/*
 * @Descroption: LeetCode 1791. 找出星型图的中心节点
 * @Author: EmoryHuang
 * @Date: 2021-08-05 20:23:42
 * @Method:
 * 简单题，寻找两条边的相同节点
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
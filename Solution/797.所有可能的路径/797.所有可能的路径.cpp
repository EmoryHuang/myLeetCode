/*
 * @Descroption: LeetCode 797. 所有可能的路径
 * @Author: EmoryHuang
 * @Date: 2021-04-17 15:51:36
 * @解题思路:
 * 因为是有向无环图，不会遍历到已经走过的节点，所以一直深度遍历即可。
 * 如果最后一个节点是目标节点那就直接加入到 ans 中
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void DFS(vector<vector<int>>& graph, int k) {
        if (k == graph.size() - 1) {  // 到达n-1
            ans.push_back(tmp);       // 加入到结果
            return;
        }
        for (int i = 0; i < graph[k].size(); i++) {
            tmp.push_back(graph[k][i]);
            DFS(graph, graph[k][i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmp.push_back(0);
        DFS(graph, 0);
        return ans;
    }
};
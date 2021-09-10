/*
 * @Descroption: LeetCode 797. ���п��ܵ�·��
 * @Author: EmoryHuang
 * @Date: 2021-04-17 15:51:36
 * @����˼·:
 * ��Ϊ�������޻�ͼ������������Ѿ��߹��Ľڵ㣬����һֱ��ȱ������ɡ�
 * ������һ���ڵ���Ŀ��ڵ��Ǿ�ֱ�Ӽ��뵽 ans ��
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void DFS(vector<vector<int>>& graph, int k) {
        if (k == graph.size() - 1) {  // ����n-1
            ans.push_back(tmp);       // ���뵽���
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
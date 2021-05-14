class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void DFS(vector<vector<int>>& graph,int k){
        if(k==graph.size()-1){// 到达n-1
            ans.push_back(tmp);// 加入到结果
            return;
        }
        for(int i=0;i<graph[k].size();i++){
            tmp.push_back(graph[k][i]);
            DFS(graph,graph[k][i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        tmp.push_back(0);
        DFS(graph,0);
        return ans;
    }
};
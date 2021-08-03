/*
 * @Descroption: LeetCode 1306. 跳跃游戏 III
 * @Author: EmoryHuang
 * @Date: 2021-08-03 16:08:58
 * @Method:
 * BFS
 * 若下一个节点未超出边界或者未访问
 * 则将这个节点加入队列并标记为访问
 */


class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        int n = arr.size();
        set<int> vis;
        queue<int> q;
        vis.insert(start);
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : {u + arr[u], u - arr[u]}) {
                // 下一个节点未超出边界或者未访问
                if (v >= 0 && v < n && vis.count(v) == 0) {
                    if (arr[v] == 0) return true;
                    q.push(v);
                    vis.insert(v);
                }
            }
        }
        return false;
    }
};
/*
 * @Descroption: LeetCode 1306. ��Ծ��Ϸ III
 * @Author: EmoryHuang
 * @Date: 2021-08-03 16:08:58
 * @Method:
 * BFS
 * ����һ���ڵ�δ�����߽����δ����
 * ������ڵ������в����Ϊ����
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
                // ��һ���ڵ�δ�����߽����δ����
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
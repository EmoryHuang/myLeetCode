/*
 * @Descroption: LeetCode 841. 钥匙和房间
 * @Author: EmoryHuang
 * @Date: 2021-07-28 17:01:59
 * @Method:
 * dfs或bfs
 * 使用一个列表记录已经访问的房间，使用队列记录当前可以打开的房间号
 * 若当前房间未访问，则标记为访问，并将其中的要是加入队列
 */

class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        for (auto key : rooms[0]) q.push(key);
        set<int> ans;
        ans.insert(0);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (ans.count(num) == 0) {
                ans.insert(num);
                for (int key : rooms[num]) q.push(key);
            }
        }
        return ans.size() == n;
    }
};
/*
 * @Descroption: LeetCode 773. 滑动谜题
 * @Author: EmoryHuang
 * @Date: 2021-06-26 14:00:00
 * @解题思路:
 * BFS
 * 将 board 看作字符串，我们需要得到的 target = "123450"
 * 在当前状态 cur 中找出 0 所在的位置 x，对于每一个与 x 相邻的位置 y，
 * 我们将 cur[x] 与 cur[y] 进行交换，得到下一个新的状态 next
 * 并加入队列
 */

class Solution {
   public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450", start;  // 目标状态
        // 得到起始字符串
        for (auto row : board)
            for (auto s : row) start += s + '0';
        if (start == target) return 0;
        queue<pair<string, int>> q;
        set<string> vis;
        q.push({start, 0});  // 记录到当前状态需要 step 步
        vis.insert(start);   // 记录当前字符串是否访问
        while (!q.empty()) {
            auto [cur, step] = q.front();
            q.pop();
            if (cur == target) return step;  // 达到目标状态
            int x = cur.find('0');           // 找到 0 的位置 x
            for (auto y : neighbors[x]) {
                string next = cur;
                swap(next[x], next[y]);  //交换
                if (!vis.count(next)) {
                    vis.insert(next);
                    q.push({next, step + 1});
                }
            }
        }
        return -1;
    }
};
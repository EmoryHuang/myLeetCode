/*
 * @Descroption: LeetCode 79. 单词搜索
 * @Author: EmoryHuang
 * @Date: 2021-04-06 19:05:36
 * @解题思路: DFS
 * 首先寻找第一个字符位置，而后进行深度优先搜索，如果能搜索到，则返回 `true`，反之返回 `false`
 */

class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j,
             vector<vector<bool>>& visit) {
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[index])  //超出边界或者未找到字符
            return false;
        if (!visit[i][j]) {  //未访问
            visit[i][j] = true;
            index++;
            if (dfs(board, word, index, i - 1, j, visit) ||
                dfs(board, word, index, i + 1, j, visit) ||
                dfs(board, word, index, i, j - 1, visit) ||
                dfs(board, word, index, i, j + 1, visit)) {
                return true;
            }
            visit[i][j] = false;  // 撤销修改
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {  //从第一个字符开始寻找
                    if (dfs(board, word, 0, i, j, visit)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
/*
 * @Descroption: 剑指 Offer 12. 矩阵中的路径
 * @Author: EmoryHuang
 * @Date: 2021-06-29 21:26:00
 * @解题思路:
 * DFS
 * 通过递归，先朝一个方向搜到底，再回溯至上个节点
 * board[i][j] = ''表示已访问，不再额外开空间
 */

class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int ind) {
        int n = board.size(), m = board[0].size();
        // 如果超出范围或者未找到元素
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[ind]) return false;
        if (ind == word.size() - 1) return true;
        // 标记访问
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, ind + 1) || dfs(board, word, i - 1, j, ind + 1) ||
                   dfs(board, word, i, j + 1, ind + 1) || dfs(board, word, i, j - 1, ind + 1);
        // 还原
        board[i][j] = word[ind];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};
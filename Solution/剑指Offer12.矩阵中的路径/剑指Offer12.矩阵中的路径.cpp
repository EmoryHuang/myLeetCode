/*
 * @Descroption: ��ָ Offer 12. �����е�·��
 * @Author: EmoryHuang
 * @Date: 2021-06-29 21:26:00
 * @����˼·:
 * DFS
 * ͨ���ݹ飬�ȳ�һ�������ѵ��ף��ٻ������ϸ��ڵ�
 * board[i][j] = ''��ʾ�ѷ��ʣ����ٶ��⿪�ռ�
 */

class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int ind) {
        int n = board.size(), m = board[0].size();
        // ���������Χ����δ�ҵ�Ԫ��
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[ind]) return false;
        if (ind == word.size() - 1) return true;
        // ��Ƿ���
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, ind + 1) || dfs(board, word, i - 1, j, ind + 1) ||
                   dfs(board, word, i, j + 1, ind + 1) || dfs(board, word, i, j - 1, ind + 1);
        // ��ԭ
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
/*
 * @Descroption: LeetCode 51. N �ʺ�
 * @Author: EmoryHuang
 * @Date: 2021-05-11 17:40:36
 * @����˼·: �� LeetCode 52. N �ʺ� II �Ļ����ϸĽ����ɣ���¼ÿ�ֽⷨ�Ļʺ�λ�ã���������
 * Ϊ���ж�һ��λ�����ڵ��к�����б�����Ƿ��Ѿ��лʺ�ʹ����������col,diag,undiag�ֱ��¼ÿһ���Լ����������ÿ��б�����Ƿ��лʺ�
 * ʹ�����±������±�֮�����ȷ��ʾÿһ���Խ��ߵ�б�ߡ�
 * ʹ�����±������±�֮�ͼ�����ȷ��ʾÿһ�����Խ��ߵ�б�ߡ�
 * ÿ�η��ûʺ�ʱ������ÿ��λ���ж����Ƿ������������У�����������϶���������ǰλ�ã���ǰλ���ǿ��Է��ûʺ��λ�á�
 */

class Solution {
   public:
    void dfs(vector<vector<string>>& solutions, vector<int>& queens, int n, int row,
             vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {            // ��������
            vector<string> board;  // ��������
            for (int i = 0; i < n; i++) {
                string line = string(n, '.');
                line[queens[i]] = 'Q';
                board.push_back(line);
            }
            solutions.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                queens[row] = i;
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(solutions, queens, n, row + 1, col, diag, undiag);  // �ݹ�
                queens[row] = -1;                                       // ����
                col[i] = false;
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // col diag undiag �ֱ��ʾ�У��Խ��ߣ����Խ������Ƿ��лʺ�
        vector<bool> col(n), diag(n), undiag(n);
        vector<vector<string>> solutions;  // ��¼�ⷨ
        vector<int> queens(n, -1);         // ��¼�ʺ�λ��
        dfs(solutions, queens, n, 0, col, diag, undiag);
        return solutions;
    }
};
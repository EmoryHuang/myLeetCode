/*
 * @Descroption: LeetCode 52. N �ʺ� II
 * @Author: EmoryHuang
 * @Date: 2021-05-11 16:50:36
 * @����˼·:
 * Ϊ���ж�һ��λ�����ڵ��к�����б�����Ƿ��Ѿ��лʺ�ʹ����������col,diag,undiag�ֱ��¼ÿһ���Լ����������ÿ��б�����Ƿ��лʺ�
 * ʹ�����±������±�֮�����ȷ��ʾÿһ���Խ��ߵ�б�ߡ�
 * ʹ�����±������±�֮�ͼ�����ȷ��ʾÿһ�����Խ��ߵ�б�ߡ�
 * ÿ�η��ûʺ�ʱ������ÿ��λ���ж����Ƿ������������У�����������϶���������ǰλ�ã���ǰλ���ǿ��Է��ûʺ��λ�á�
 */

class Solution {
   public:
    int ans = 0;
    void dfs(int n, int row, vector<bool>& col, vector<bool>& diag, vector<bool>& undiag) {
        if (row == n) {  // ��������
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[row - i + n - 1] && !undiag[row + i]) {
                col[i] = true;
                diag[row - i + n - 1] = true;
                undiag[row + i] = true;
                dfs(n, row + 1, col, diag, undiag);  // �ݹ�
                col[i] = false;                      // ����
                diag[row - i + n - 1] = false;
                undiag[row + i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        // col diag undiag �ֱ��ʾ�У��Խ��ߣ����Խ������Ƿ��лʺ�
        vector<bool> col(n), diag(n), undiag(n);
        dfs(n, 0, col, diag, undiag);
        return ans;
    }
};
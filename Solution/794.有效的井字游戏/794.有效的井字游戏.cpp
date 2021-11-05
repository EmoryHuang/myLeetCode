/*
 * @Descroption: LeetCode 794. ��Ч�ľ�����Ϸ
 * @Author: EmoryHuang
 * @Date: 2021-11-05 15:49:25
 * @Method:
 * �����ж������Ƿ��������
 * Ȼ����������ж��Ƿ����Ӯ�ң�������������Ҫ��
 */

class Solution {
   public:
    bool win(vector<string>& board, char c) {
        for (int i = 0; i < 3; i++) {
            if (c == board[i][0] && c == board[i][1] && c == board[i][2]) return true;
            if (c == board[0][i] && c == board[1][i] && c == board[2][i]) return true;
        }
        return (c == board[0][0] && c == board[1][1] && c == board[2][2]) ||
               (c == board[0][2] && c == board[1][1] && c == board[2][0]);
    }
    bool validTicTacToe(vector<string>& board) {
        unordered_map<char, int> cnt;
        for (auto s : board)
            for (auto c : s) cnt[c]++;
        // �ж������Ƿ��������
        if (cnt['X'] != cnt['O'] && cnt['X'] != cnt['O'] + 1) return false;
        if (win(board, 'X') && cnt['X'] != cnt['O'] + 1) return false;
        if (win(board, 'O') && cnt['X'] != cnt['O']) return false;
        return true;
    }
};
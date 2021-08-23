/*
 * @Descroption: LeetCode 1138. 字母板上的路径
 * @Author: EmoryHuang
 * @Date: 2021-08-23 16:07:58
 * @Method:
 * 由于字母板是比较规则的，因此可以计算出当前字母所在的行列
 * 并与前一个字符所在的位置进行比较，根据相对位置确定路径
 * 注意，由于 z 右边没有位置，因此先满足 z，移动时 R 的优先级最低
 */

class Solution {
   public:
    string alphabetBoardPath(string target) {
        int row = 0, col = 0;
        string ans;
        for (auto c : target) {
            // 更新前一个字符的位置
            int prow = row, pcol = col;
            // 当前字符所在的位置
            row = (c - 'a') / 5;
            col = (c - 'a') % 5;
            while (pcol > col) ans += 'L', pcol--;
            while (prow < row) ans += 'D', prow++;
            while (prow > row) ans += 'U', prow--;
            while (pcol < col) ans += 'R', pcol++;
            ans += '!';
        }
        return ans;
    }
};
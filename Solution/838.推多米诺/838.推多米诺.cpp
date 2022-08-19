/*
 * @Descroption: LeetCode 838. 推多米诺
 * @Author: EmoryHuang
 * @Date: 2022-02-21 09:12:18
 * @Method:
 * 双指针
 * 找到一段连续的未被施加力的区间，通过左右两边的方向来确定该区间的倒向
 * left 和 right 表示改区间左右两边推倒的方向
 * 方向相同，则往一个方向倒；方向相对，向中间倒
 */

class Solution {
   public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        // left 和 right 表示推倒的方向
        char left = 'L';
        while (i < n) {
            int j = i;
            // 找到一段连续的未被施加力的区间
            while (j < n && dominoes[j] == '.') j++;
            char right = j < n ? dominoes[j] : 'R';
            if (left == right)
                // 方向相同，往一个方向倒
                while (i < j) dominoes[i++] = right;
            else if (left == 'R' && right == 'L') {
                // 方向相对，向中间倒
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};
/*
 * @Descroption: LeetCode 598. ��Χ��� II
 * @Author: EmoryHuang
 * @Date: 2021-09-13 16:21:40
 * @Method:
 * ���⣬�����޸ĵķ�Χʼ����һ�������Ͻǿ�ʼ�ľ���
 * ��ôֻҪ�õ���С�Ĳ������м���ȷ�����ֵ���ڵľ���
 */

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m, col = n;
        for (auto c : ops) {
            row = min(row, c[0]);
            col = min(col, c[1]);
        }
        return row * col;
    }
};
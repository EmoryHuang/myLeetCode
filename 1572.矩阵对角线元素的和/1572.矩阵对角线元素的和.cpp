/*
 * @Descroption: LeetCode 1572. ����Խ���Ԫ�صĺ�
 * @Author: EmoryHuang
 * @Date: 2021-08-14 14:19:53
 * @Method:
 * ��Ϊ�������ξ������Կ���ֱ�ӵõ��ĸ�λ�õ�ֵ������һ�鼴��
 * ��Ϊ����Ԫ�أ�ֻ��Ҫ��һ��
 */

class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - i - 1)
                ans += mat[i][i];
            else
                ans += mat[i][i] + mat[i][n - i - 1];
        }
        return ans;
    }
};
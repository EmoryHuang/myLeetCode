/*
 * @Descroption: LeetCode 944. ɾ������
 * @Author: EmoryHuang
 * @Date: 2022-05-12 08:55:57
 * @Method:
 * ���⣬�����Ƚϵ�ǰ�к���һ��Ԫ�ؼ���
 */


class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n - 1; i++) {
                if (strs[i][j] > strs[i + 1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
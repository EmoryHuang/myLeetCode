/*
 * @Descroption: LCP 01. ������
 * @Author: EmoryHuang
 * @Date: 2021-07-08 18:43:43
 * @����˼·:
 * ���⣬����һ��
 */

class Solution {
   public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans = 0;
        for (int i = 0; i < 3; i++)
            if (guess[i] == answer[i]) ans++;
        return ans;
    }
};
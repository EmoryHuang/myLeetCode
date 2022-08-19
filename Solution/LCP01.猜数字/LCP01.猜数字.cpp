/*
 * @Descroption: LCP 01. 猜数字
 * @Author: EmoryHuang
 * @Date: 2021-07-08 18:43:43
 * @解题思路:
 * 简单题，遍历一遍
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
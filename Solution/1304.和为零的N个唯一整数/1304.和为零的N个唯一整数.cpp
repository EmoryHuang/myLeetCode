/*
 * @Descroption: LeetCode 1304. 和为零的N个唯一整数
 * @Author: EmoryHuang
 * @Date: 2021-07-26 15:18:19
 * @Method:
 * 简单题，一正一负
 */

class Solution {
   public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2 == 1) ans.push_back(0);
        for (int i = 1; i < n / 2 + 1; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};
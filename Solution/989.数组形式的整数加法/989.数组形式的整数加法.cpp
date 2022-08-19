/*
 * @Descroption: LeetCode 989. 数组形式的整数加法
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:06:36
 * @解题思路:
 * 类似大数加法问题，从最低位开始计算
 */

class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int len = num.size();
        vector<int> ans;
        for (int i = len - 1; i >= 0; i--) {
            int tmp = num[i] + k;
            ans.insert(ans.begin(), tmp % 10);
            k = tmp / 10;
        }
        while (k > 0) {
            ans.insert(ans.begin(), k % 10);
            k /= 10;
        }
        return ans;
    }
};
/*
 * @Descroption: 剑指 Offer 17. 打印从 1 到最大的 n 位数
 * @Author: EmoryHuang
 * @Date: 2021-06-27 15:45:00
 * @解题思路:
 * 不考虑大数问题的话直接往里加就行
 */

class Solution {
   public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        for (int i = 1; i < pow(10, n); i++) ans.push_back(i);
        return ans;
    }
};
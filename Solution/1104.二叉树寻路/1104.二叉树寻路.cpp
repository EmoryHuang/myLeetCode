/*
 * @Descroption: LeetCode 1104. 二叉树寻路
 * @Author: EmoryHuang
 * @Date: 2021-07-29 13:38:01
 * @Method:
 * 数学
 * 若为偶数行，则将从左到右与从右到左进行转换
 * label = 2^(i - 1) + 2^(i) - 1 - label
 */

class Solution {
   public:
    vector<int> pathInZigZagTree(int label) {
        int row = 1, start = 1;
        vector<int> ans;
        while (start * 2 <= label) {
            row++;
            start *= 2;
        }
        if (row % 2 == 0) label = (1 << row - 1) + (1 << row) - 1 - label;
        while (row) {
            if (row % 2 == 0)
                ans.push_back((1 << row - 1) + (1 << row) - 1 - label);
            else
                ans.push_back(label);
            row--;
            label >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
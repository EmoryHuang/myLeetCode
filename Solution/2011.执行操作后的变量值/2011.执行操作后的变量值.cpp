/*
 * @Descroption: LeetCode 2011. 执行操作后的变量值
 * @Author: EmoryHuang
 * @Date: 2021-10-15 19:54:47
 * @Method:
 * 简单题，模拟
 */


class Solution {
   public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto op : operations) {
            if (op[1] == '+')
                x++;
            else if (op[1] == '-')
                x--;
        }
        return x;
    }
};
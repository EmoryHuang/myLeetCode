/*
 * @Descroption: LeetCode 1881. 插入后的最大值
 * @Author: EmoryHuang
 * @Date: 2021-09-10 20:21:30
 * @Method:
 * 如果 n 是负数，寻找 n 中第一个比 x 大的位置插入
 * 如果 n 是正数，寻找 n 中第一个比 x 小的位置插入
 */

class Solution {
   public:
    string maxValue(string n, int x) {
        int len = n.size();
        if (n[0] == '-') {
            for (int i = 1; i < len; i++)
                if (n[i] - '0' > x) {
                    n.insert(i, 1, x + '0');
                    return n;
                }
            n.push_back(x + '0');
            return n;
        } else {
            for (int i = 0; i < len; i++)
                if (n[i] - '0' < x) {
                    n.insert(i, 1, x + '0');
                    return n;
                }
            n.push_back(x + '0');
            return n;
        }
    }
};
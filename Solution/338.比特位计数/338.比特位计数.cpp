/*
 * @Descroption: LeetCode 338. 比特位计数
 * @Author: EmoryHuang
 * @Date: 2021-03-26 10:29:36
 * @解题思路:
 * 奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1
 * 举例：
 *     0 = 0       1 = 1
 *     2 = 10      3 = 11
 * 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多
 * 举例：
 *     2 = 10       4 = 100       8 = 1000
 *     3 = 11       6 = 110       12 = 1100
 */

class Solution {
   public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        ans[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i / 2] + 1;
        }
        return ans;
    }
};
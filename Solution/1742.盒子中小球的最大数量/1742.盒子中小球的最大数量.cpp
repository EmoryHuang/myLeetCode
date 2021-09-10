/*
 * @Descroption: LeetCode 1742. 盒子中小球的最大数量
 * @Author: EmoryHuang
 * @Date: 2021-05-25 13:04:11
 * @解题思路:
 * 哈希表记录每个盒子中的小球数量，取最大值
 */

class Solution {
   public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> sum(50);
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int x = i, box = 0;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            sum[box]++;
            ans = max(ans, sum[box]);
        }
        return ans;
    }
};
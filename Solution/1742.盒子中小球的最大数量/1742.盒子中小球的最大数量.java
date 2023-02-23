/*
 * @Descroption: LeetCode 1742. 盒子中小球的最大数量
 * @Author: EmoryHuang
 * @Date: 2022-11-23 09:12:15
 * @Method:
 * 使用哈希表记录每个盒子的小球数量
 */


class Solution {
    public int countBalls(int lowLimit, int highLimit) {
        int[] hash = new int[50];
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = 0, num = i;
            while (num != 0) {
                box += num % 10;
                num /= 10;
            }
            hash[box]++;
            ans = Math.max(ans, hash[box]);
        }
        return ans;
    }
}
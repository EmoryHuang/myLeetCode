/*
 * @Descroption: LeetCode 1732. 找到最高海拔
 * @Author: EmoryHuang
 * @Date: 2021-05-25 12:57:11
 * @解题思路:
 * 遍历数组，记录当前海拔高度，更新最大值
 */

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for (int g : gain) {
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};
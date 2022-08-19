/*
 * @Descroption: LeetCode 1893. 检查是否区域内所有整数都被覆盖
 * @Author: EmoryHuang
 * @Date: 2021-07-20 20:15:26
 * @解题思路:
 * 遍历闭区间内的每一个整数，记录位于区间内的元素的数量
 */

class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cnt = 0;
        for (int i = left; i <= right; i++)
            for (auto range : ranges)
                if (i >= range[0] && i <= range[1]) {
                    cnt++;
                    break;
                }
        return cnt == right - left + 1;
    }
};
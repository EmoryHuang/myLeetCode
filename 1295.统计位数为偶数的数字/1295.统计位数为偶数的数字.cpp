/*
 * @Descroption: LeetCode 1295. 统计位数为偶数的数字
 * @Author: EmoryHuang
 * @Date: 2021-07-19 18:56:42
 * @解题思路:
 * 遍历数组，计数偶数长度的数量
 */

class Solution {
   public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto num : nums)
            if (to_string(num).size() % 2 == 0) cnt++;
        return cnt;
    }
};
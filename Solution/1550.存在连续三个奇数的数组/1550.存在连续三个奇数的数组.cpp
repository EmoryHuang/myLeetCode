/*
 * @Descroption: LeetCode 1550. 存在连续三个奇数的数组
 * @Author: EmoryHuang
 * @Date: 2021-04-22 14:40:36
 * @解题思路:
 * 简单题，奇偶数判断
 */

class Solution {
   public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;
        for (int i = 0; i < arr.size() - 2; i++)
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) return true;
        return false;
    }
};
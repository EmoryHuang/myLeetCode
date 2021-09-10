/*
 * @Descroption: LeetCode 1502. 判断能否形成等差数列
 * @Author: EmoryHuang
 * @Date: 2021-04-22 15:20:36
 * @解题思路:
 * 先排序，然后遍历查看公差是否相等
 */

class Solution {
   public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int d = arr[0] - arr[1];
        for (int i = 0; i < arr.size() - 1; i++)
            if (arr[i] - arr[i + 1] != d) return false;
        return true;
    }
};
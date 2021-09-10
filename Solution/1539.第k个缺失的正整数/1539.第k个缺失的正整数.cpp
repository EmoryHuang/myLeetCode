/*
 * @Descroption: LeetCode 1539. 第 k 个缺失的正整数
 * @Author: EmoryHuang
 * @Date: 2021-04-22 14:56:36
 * @解题思路:
 * 缺失的正整数一定 >= k
 * 数组中每出现一个 <= k 的数字，意味着少了一个缺失的数字，此时 k+1
 */

class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++)
            if (k >= arr[i]) k++;
        return k;
    }
};
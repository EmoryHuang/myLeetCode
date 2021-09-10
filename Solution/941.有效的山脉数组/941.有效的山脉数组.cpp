/*
 * @Descroption: LeetCode 941. 有效的山脉数组
 * @Author: EmoryHuang
 * @Date: 2021-06-04 13:54:00
 * @解题思路:
 * 分别从左到右，从右到左进行遍历，找到山顶
 */

class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r && arr[l] < arr[l + 1]) l++;
        while (l < r && arr[r] < arr[r - 1]) r--;
        return l == r && l != 0 && r != arr.size() - 1;
    }
};
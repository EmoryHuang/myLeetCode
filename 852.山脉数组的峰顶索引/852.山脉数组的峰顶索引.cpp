/*
 * @Descroption: LeetCode 852. 山脉数组的峰顶索引
 * @Author: EmoryHuang
 * @Date: 2021-04-25 14:06:36
 * @解题思路:
 * 简单题，遍历数组，找到第一个`arr[i] > arr[i + 1]`的元素
 */

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i;
        for (i = 0; i < arr.size() - 1; i++)
            if (arr[i] - arr[i + 1] > 0) break;
        return i;
    }
};
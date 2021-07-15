/*
 * @Descroption: LeetCode 1846. 减小和重新排列数组后的最大元素
 * @Author: EmoryHuang
 * @Date: 2021-07-15 18:48:44
 * @解题思路:
 * 排序后遍历数组，第一项为 1
 * 若arr[i]与arr[i - 1]之差大于 1，则令arr[i] = arr[i - 1] + 1
 */

class Solution {
   public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        return arr[arr.size() - 1];
    }
};
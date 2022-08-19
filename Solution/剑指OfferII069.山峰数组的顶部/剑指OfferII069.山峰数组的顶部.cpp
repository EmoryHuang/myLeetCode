/*
 * @Descroption: 剑指 Offer II 069. 山峰数组的顶部
 * @Author: EmoryHuang
 * @Date: 2021-08-06 18:29:30
 * @Method:
 * 二分法寻找左端点
 */

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        // 二分法寻找左端点
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] >= arr[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
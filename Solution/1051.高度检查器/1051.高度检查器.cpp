/*
 * @Descroption: LeetCode 1051. 高度检查器
 * @Author: EmoryHuang
 * @Date: 2021-07-17 14:35:29
 * @解题思路:
 * 一个很简单的思想是将原数组进行排序，然后将排序后的数组与原数组进行比较
 * 然后计数有多少个元素没到指定的位置
 *
 * 采用桶排序的思想可以避免排序，时间复杂度为O(n)
 */

class Solution {
   public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr(101);
        for (auto height : heights) arr[height]++;
        int ans = 0, j = 0;
        for (int i = 1; i < arr.size(); i++) {
            while (arr[i]-- > 0)
                if (heights[j++] != i) ans++;
        }
        return ans;
    }
};
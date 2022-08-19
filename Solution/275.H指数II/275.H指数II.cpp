/*
 * @Descroption: LeetCode 275. H 指数 II
 * @Author: EmoryHuang
 * @Date: 2021-04-05 18:38:36
 * @解题思路:
 * 方法一与 [274. H 指数]相同
 * 先对数组进行排序，
 * 设`h = citations.length - i`，即至多有`h`篇论文分别引用了至少`citation[i]`次
 * 只要`citation[i] ≥ h`，就满足题意
 *
 * 方法二为二分搜索，
 * 找到满足 `citations[i] >= n - i` 的第一个 `citations[i]`
 */

class Solution {
   public:
    // 方法一：遍历
    // int hIndex(vector<int>& citations) {
    //     int len = citations.size();
    //     for (int i = 0; i < len; i++) {
    //         int h = len - i;
    //         if (h <= citations[i]) return h;
    //     }
    //     return 0;
    // }

    // 方法二：二分搜索
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] == len - mid)
                return len - mid;
            else if (citations[mid] > len - mid)
                right = mid - 1;
            else
                left = left + 1;
        }
        return len - left;
    }
};
/*
 * @Descroption: LeetCode 274. H 指数
 * @Author: EmoryHuang
 * @Date: 2021-07-11 13:25:04
 * @解题思路:
 * 排序后二分，二分法寻找右端点
 */

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            // 倒数第 mid 个数如果满足条件
            if (citations[n - mid] >= mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
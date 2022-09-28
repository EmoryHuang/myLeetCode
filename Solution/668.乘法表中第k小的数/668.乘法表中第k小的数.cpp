/*
 * @Descroption: LeetCode 668. 乘法表中第k小的数
 * @Author: EmoryHuang
 * @Date: 2022-05-18 09:15:08
 * @Method:
 * 二分查找
 * left = 1, right = m * n + 1, mid = (left + right) // 2
 * 每次寻找乘法表中小于等于 mid 的数的个数 cnt
 * 若 cnt == k, 则说明找到了第 k 小的数
 * 其中 cnt = sum_{i = 1}^{m} min(mid // i, n)
 */


class Solution {
   public:
    int count(int num, int m, int n) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) cnt += min(num / i, n);
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (count(mid, m, n) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
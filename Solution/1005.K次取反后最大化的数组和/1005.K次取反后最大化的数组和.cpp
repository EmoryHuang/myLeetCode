/*
 * @Descroption: LeetCode 1005. K 次取反后最大化的数组和
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:05:36
 * @解题思路:
 * 首先对数组进行排序，并设置指向最小元素的指针 `cur`，对这个元素取反，
 * 若 `A[cur] > A[cur + 1]` 则指针前进，令其指向更小的元素，重复 `K` 次
 */

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int cur = 0, ans = 0;
        for (int i = 0; i < K; i++) {
            A[cur] = -A[cur];
            if (A[cur] > A[cur + 1]) cur++;
        }
        for (int num : A) ans += num;
        return ans;
    }
};
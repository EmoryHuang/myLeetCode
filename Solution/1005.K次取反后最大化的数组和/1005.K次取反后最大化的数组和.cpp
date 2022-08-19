/*
 * @Descroption: LeetCode 1005. K 次取反后最大化的数组和
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:05:36
 * @解题思路:
 * 首先对数组进行排序，并设置指向最小元素的指针 `cur`，对这个元素取反，
 * 若 `A[cur] > A[cur + 1]` 则指针前进，令其指向更小的元素，重复 `K` 次
 * 如果 k 还没有结束，那就考虑取反后最小的数字
 */

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int ans = 0;
        for (int i = 0; i < A.size() && K; i++, K--) {
            if (A[i] > 0) break;
            A[i] *= -1;
        }
        sort(A.begin(), A.end());
        while(K--) A[0] *= -1;
        for (int num : A) ans += num;
        return ans;
    }
};
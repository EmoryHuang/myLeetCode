/*
 * @Descroption: LeetCode 896. 单调数列
 * @Author: EmoryHuang
 * @Date: 2021-04-25 14:44:36
 * @解题思路:
 * 若同时有`A[i] < A[i + 1]`和`A[i] > A[i + 1]`，则不是单调数列
 */

class Solution {
   public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] < A[i + 1])
                inc = false;
            else if (A[i] > A[i + 1])
                dec = false;
        }
        return inc || dec;
    }
};
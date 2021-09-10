/*
 * @Descroption: LeetCode 908. 最小差值 I
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:09:36
 * @解题思路:
 * 简单题，主要在于理解题目意思，加上的数在`-K <= x <= K`之间
 */

class Solution {
   public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxA = INT_MIN, minA = INT_MAX;
        for (int num : A) {
            maxA = max(maxA, num);
            minA = min(minA, num);
        }
        return max(0, maxA - minA - 2 * K);
    }
};
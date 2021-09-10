/*
 * @Descroption: LeetCode 908. ��С��ֵ I
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:09:36
 * @����˼·:
 * ���⣬��Ҫ���������Ŀ��˼�����ϵ�����`-K <= x <= K`֮��
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
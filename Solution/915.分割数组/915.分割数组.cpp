/*
 * @Descroption: LeetCode 915. 分割数组
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:27:36
 * @解题思路:
 * 因为题目保证有划分，那么可以设置两个值，左侧最大值和全局最大值，找到第一个比左侧数字都大的值
 */

class Solution {
   public:
    int partitionDisjoint(vector<int>& A) {
        if (A.size() == 0) return 0;
        int maxA = A[0], maxLeft = A[0];
        int pos = 0;
        for (int i = 0; i < A.size(); i++) {
            maxA = max(maxA, A[i]);
            if (maxLeft > A[i]) {  // 找到第一个比左侧数字都大的值
                maxLeft = maxA;
                pos = i;
            }
        }
        return pos + 1;
    }
};
/*
 * @Descroption: LeetCode 896. ��������
 * @Author: EmoryHuang
 * @Date: 2021-04-25 14:44:36
 * @����˼·:
 * ��ͬʱ��`A[i] < A[i + 1]`��`A[i] > A[i + 1]`�����ǵ�������
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
/*
 * @Descroption: LeetCode 905. ����ż��������
 * @Author: EmoryHuang
 * @Date: 2021-04-27 13:59:36
 * @����˼·:
 * ����һ�飬����ָ�룬���ý�����˼�룬��ż��Ԫ�طŵ�ǰ��
 */

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        for (int j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) {
                swap(A[i], A[j]);
                i++;
            }
        return A;
    }
};
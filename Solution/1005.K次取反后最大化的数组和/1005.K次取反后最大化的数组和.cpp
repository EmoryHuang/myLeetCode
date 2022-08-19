/*
 * @Descroption: LeetCode 1005. K ��ȡ������󻯵������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:05:36
 * @����˼·:
 * ���ȶ�����������򣬲�����ָ����СԪ�ص�ָ�� `cur`�������Ԫ��ȡ����
 * �� `A[cur] > A[cur + 1]` ��ָ��ǰ��������ָ���С��Ԫ�أ��ظ� `K` ��
 * ��� k ��û�н������ǾͿ���ȡ������С������
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
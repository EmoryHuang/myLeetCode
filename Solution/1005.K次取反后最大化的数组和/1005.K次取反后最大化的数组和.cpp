/*
 * @Descroption: LeetCode 1005. K ��ȡ������󻯵������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:05:36
 * @����˼·:
 * ���ȶ�����������򣬲�����ָ����СԪ�ص�ָ�� `cur`�������Ԫ��ȡ����
 * �� `A[cur] > A[cur + 1]` ��ָ��ǰ��������ָ���С��Ԫ�أ��ظ� `K` ��
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
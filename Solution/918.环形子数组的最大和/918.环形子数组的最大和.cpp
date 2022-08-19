/*
 * @Descroption: LeetCode 918. ���������������
 * @Author: EmoryHuang
 * @Date: 2021-04-27 14:46:36
 * @����˼·:
 * ��ʹ�û���ͨ����̬�滮ֱ�Ӽ����������ͣ�`dp[i]` Ϊ�� `A[i]` ��β������Ӷκ͡�
 * 
 * ʹ�û�����ʹ�õ��˻�����ض����� `A[n-1]` �� `A[0]` ����Ԫ�أ����Ҵ� `A[1]` �� `A[n-2]`
 * ����������бض��������������ֻ��Ҫ�� `A[1] - A[n-2]` �����С���������
 * ����������ĺ� `sum` �������������С�ͼ���ʵ�ֻ������������
 */

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& A) {
        int len = A.size();
        vector<int> dp(len);
        dp[0] = A[0];
        int sum = A[0];        //��������ĺ�
        int maxSum = INT_MIN;  //��������
        for (int i = 1; i < len; i++) {
            sum += A[i];
            dp[i] = max(dp[i - 1] + A[i], A[i]);
            maxSum = max(maxSum, dp[i]);
        }
        int minSum = 0;  // A[1]-A[n-1]����С�����
        for (int i = 1; i < len - 1; i++) {
            dp[i] = min(dp[i - 1] + A[i], A[i]);
            minSum = min(minSum, dp[i]);
        }
        return max(sum - minSum, maxSum);
    }
};
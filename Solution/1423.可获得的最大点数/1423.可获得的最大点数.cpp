/*
 * @Descroption: LeetCode 1423. �ɻ�õ�������
 * @Author: EmoryHuang
 * @Date: 2021-09-17 19:28:03
 * @Method:
 * ��������
 * �������ڴ�СΪ n - k
 * ��֤����������Ԫ����С��Ҳ����ʣ�µ�Ԫ����С
 */

class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < n - k; i++) sum += cardPoints[i];
        int ans = sum;
        for (int i = n - k; i < n; i++) {
            sum += cardPoints[i] - cardPoints[i - n + k];
            ans = min(ans, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - ans;
    }
};
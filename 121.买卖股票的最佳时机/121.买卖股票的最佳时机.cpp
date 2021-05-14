/*
 * @Descroption: LeetCode 121. ������Ʊ�����ʱ��
 * @Author: EmoryHuang
 * @Date: 2021-03-25 10:45:36
 * @����˼·: �򵥵Ķ�̬�滮����
 * �� i ����Ի�õ�������� =
 * MAX ���� i-1 ����Ի�õ�������󣬵� i ��ļ۸� - ǰ i-1 ���е���С�۸�
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int minp = prices[0], maxp = 0;
        for (int i = 1; i < len; i++) {
            maxp = max(maxp, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};
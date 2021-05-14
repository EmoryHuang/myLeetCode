/*
 * @Descroption: LeetCode 122. ������Ʊ�����ʱ�� II
 * @Author: EmoryHuang
 * @Date: 2021-03-25 09:30:36
 * @����˼·:
 * ��ʵ��Ŀ����˼���Խ��м򻯣�ֻҪ����ļ۸������ĸ߾Ϳ�������������벻��ͬʱ������һ����
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i]) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
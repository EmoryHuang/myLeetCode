/*
 * @Descroption: ��ָ Offer 63. ��Ʊ���������
 * @Author: EmoryHuang
 * @Date: 2021-07-04 13:58:45
 * @����˼·:
 * ��Ϊ�����һ����������֮ǰ�����ά��һ����Сֵ�������۸�Ѱ���������
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int ans = 0, min = INT_MAX;
        for (int price : prices) {
            if (price < min)
                min = price;
            else
                ans = max(ans, price - min);
        }
        return ans;
    }
};
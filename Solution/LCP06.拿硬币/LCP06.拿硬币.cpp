/*
 * @Descroption: LCP 06. ��Ӳ��
 * @Author: EmoryHuang
 * @Date: 2021-07-08 18:50:15
 * @����˼·:
 * ���⣬����2����ȡ��
 */

class Solution {
   public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (double coin : coins) ans += ceil(coin / 2);
        return ans;
    }
};
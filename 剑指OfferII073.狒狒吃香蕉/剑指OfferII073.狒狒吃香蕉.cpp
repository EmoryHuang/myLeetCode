/*
 * @Descroption: ��ָ Offer II 073. �������㽶
 * @Author: EmoryHuang
 * @Date: 2021-08-06 18:50:18
 * @Method:
 * ���ַ�Ѱ�����п��ܵ��ٶȣ��жϵ�ǰ�ٶ��Ƿ�����Ҫ��
 */

class Solution {
   public:
    bool check(vector<int>& piles, int h, int s) {
        int cnt = 0;
        for (int pile : piles) cnt += ceil(1.0 * pile / s);
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) return ceil(1.0 * piles[0] / h);
        int l = 0, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(piles, h, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
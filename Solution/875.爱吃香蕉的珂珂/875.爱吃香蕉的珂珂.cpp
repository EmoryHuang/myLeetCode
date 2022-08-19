/*
 * @Descroption: LeetCode 875. �����㽶������
 * @Author: EmoryHuang
 * @Date: 2021-07-21 20:09:23
 * @����˼·:
 * ���ַ�Ѱ�����п��ܵ��ٶȣ��жϵ�ǰ�ٶ��Ƿ�����Ҫ��
 */

class Solution {
   public:
    bool check(vector<int>& piles, int h, int k) {
        int cnt = 0;
        for (auto pile : piles) cnt += ceil((double)pile / k);
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.size() == 1) return ceil((double)piles[0] / h);
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(piles, h, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
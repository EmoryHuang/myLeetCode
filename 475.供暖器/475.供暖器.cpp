/*
 * @Descroption: LeetCode 475. ��ů��
 * @Author: EmoryHuang
 * @Date: 2021-06-08 21:05:00
 * @����˼·:
 * ���ַ�
 * ����ÿ�� house, Ѱ�Ҿ��� house ����� heater
 * ����λ�� heater ��࣬��С��Ӧ���� heaters[l] - house
 * ����λ�� heater �Ҳ࣬��С��Ӧ���� house - heaters[r]
 */

class Solution {
   public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        heaters.push_back(INT_MIN);
        heaters.push_back(INT_MAX);
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = heaters.size(), ans = 0;
        for (int house : houses) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (heaters[mid] >= house)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans = max((long)ans, min((long)heaters[l] - house, (long)house - heaters[r - 1]));
        }
        return ans;
    }
};
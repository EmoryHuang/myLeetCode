/*
 * @Descroption: LeetCode 475. 供暖器
 * @Author: EmoryHuang
 * @Date: 2021-06-08 21:05:00
 * @解题思路:
 * 二分法
 * 遍历每个 house, 寻找距离 house 最近的 heater
 * 房子位于 heater 左侧，最小就应该是 heaters[l] - house
 * 房子位于 heater 右侧，最小就应该是 house - heaters[r]
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
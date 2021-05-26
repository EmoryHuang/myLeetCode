/*
 * @Descroption: LeetCode 1184. 公交站间的距离
 * @Author: EmoryHuang
 * @Date: 2021-05-26 16:17:17
 * @解题思路:
 * 因为公交站是环形，因此只有两种走法，正着走或者反着走
 * 只要取较小值即可
 */

class Solution {
   public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, l, r;
        for (int num : distance) sum += num;
        l = min(start, destination);  // 较小值为起点
        r = max(start, destination);  // 较大值为终点
        int ans = 0;
        for (int i = 0; i < distance.size(); i++)
            if (i >= l && i < r) ans += distance[i];
        return min(ans, sum - ans);  // 正向走或反向走
    }
};
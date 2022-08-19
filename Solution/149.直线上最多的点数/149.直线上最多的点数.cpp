/*
 * @Descroption: LeetCode 149. 直线上最多的点数
 * @Author: EmoryHuang
 * @Date: 2021-06-24 15:27:00
 * @解题思路:
 * 方法一：暴力遍历
 * 遍历任意两个点，然后比较与其他点的斜率是否相同，找到最大值
 * 方法二：哈希表存储
 * 计算两个点之间的斜率，用哈希表记录斜率出现的次数
 * 出现次数最多的斜率即为直线上最多的点数
 */

class Solution {
   public:
    // 方法一：暴力遍历
    // int maxPoints(vector<vector<int>>& points) {
    //     int ans = 1, n = points.size();
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             int cnt = 2;
    //             for (int k = j + 1; k < n; k++) {
    //                 vector<int> x = points[i], y = points[j], z = points[k];
    //                 int d1 = (y[1] - x[1]) * (z[0] - y[0]);
    //                 int d2 = (z[1] - y[1]) * (y[0] - x[0]);
    //                 if (d1 == d2) cnt++;
    //             }
    //             ans = max(ans, cnt);
    //         }
    //     }
    //     return ans;
    // }

    // 方法二：哈希表存储
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            for (int j = i + 1; j < n; j++) {
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                double k = dx != 0 ? dy / dx : 0x3f3f3f3f;
                if (mp.count(k) != 0)
                    mp[k]++;
                else
                    mp[k] = 2;
                ans = max(ans, mp[k]);
            }
        }
        return ans;
    }
};
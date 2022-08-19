/*
 * @Descroption: LeetCode 1620. 网络信号最好的坐标
 * @Author: EmoryHuang
 * @Date: 2021-11-05 20:11:22
 * @Method:
 * 遍历所有点，找到网络信号最好的坐标
 */

class Solution {
   public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ans = {0, 0};
        int maxq = 0;
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                int cur = 0;
                for (auto t : towers) {
                    int x = t[0], y = t[1], q = t[2];
                    double d = sqrt((x - i) * (x - i) + (y - j) * (y - j));
                    if (d <= radius) cur += (int)q / (1 + d);
                }
                if (cur > maxq) {
                    maxq = cur;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};
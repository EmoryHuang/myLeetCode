/*
 * @Descroption: LeetCode 149. ֱ�������ĵ���
 * @Author: EmoryHuang
 * @Date: 2021-06-24 15:27:00
 * @����˼·:
 * ����һ����������
 * �������������㣬Ȼ��Ƚ����������б���Ƿ���ͬ���ҵ����ֵ
 * ����������ϣ��洢
 * ����������֮���б�ʣ��ù�ϣ���¼б�ʳ��ֵĴ���
 * ���ִ�������б�ʼ�Ϊֱ�������ĵ���
 */

class Solution {
   public:
    // ����һ����������
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

    // ����������ϣ��洢
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
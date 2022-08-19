/*
 * @Descroption: LeetCode 1610. �ɼ���������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-12-16 09:19:23
 * @Method:
 * ��ѧ + ��������
 * ʹ�ù�ʽ����������֮��ļнǣ�point �� location, x��ĵ�λ������
 * theta = atan2(p[1] - location[1], p[0] - location[0])
 * Ȼ�󰴻��Ƚ�������ʹ�û�������ͳ���ӽ��ڿɼ���������Ŀ
 * ע��� location �غϵĵ�
 * */

class Solution {
   public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int same = 0, ans = 0;
        vector<double> angle_point;
        for (auto& point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                same++;
                continue;
            }
            double degree = atan2(point[1] - location[1], point[0] - location[0]);
            angle_point.emplace_back(degree);
        }
        sort(angle_point.begin(), angle_point.end());
        int n = angle_point.size();
        for (int i = 0; i < n; i++) {
            angle_point.emplace_back(angle_point[i] + 2 * M_PI);
        }
        int r = 0;
        for(int i = 0; i < n; i++){
            while (r < n * 2 && angle_point[r] - angle_point[i] <= angle * M_PI / 180) r++;
            ans = max(ans, r - i);
        }
        return ans + same;
    }
};
/*
 * @Descroption: LeetCode 452. �����������ļ���������
 * @Author: EmoryHuang
 * @Date: 2021-08-12 20:01:27
 * @Method:
 * ̰��
 * �����Ҷ˵�����
 * ����˵���֮ǰ������ֵ���Ƚϣ��ҵ���ǰ�����������������
 */

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
        int pre = points[0][1];
        int ans = 1;
        for (auto point : points) {
            if (point[0] > pre) {
                ans++;
                pre = point[1];
            }
        }
        return ans;
    }
};
/*
 * @Descroption: LeetCode 1637. ����֮�䲻�����κε�����ֱ���
 * @Author: EmoryHuang
 * @Date: 2021-10-18 18:45:30
 * @Method:
 * �� x ��С��������Ѱ�������
 */

class Solution {
   public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            ans = max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};
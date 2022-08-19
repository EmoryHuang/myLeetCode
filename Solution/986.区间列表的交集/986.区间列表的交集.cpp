/*
 * @Descroption: LeetCode 986. �����б�Ľ���
 * @Author: EmoryHuang
 * @Date: 2021-06-06 15:50:00
 * @����˼·:
 * ������ָ�룬�ֱ�ɨ�� A��B ���飬��������������Ҷˣ����һ����������
 * �����������ˣ�ȡ���ǵĽϴ���
 * ����������Ҷˣ�ȡ���ǵĽ�С��
 * ����һ����������󣬽�������������䣬ָ���ƶ�
 */

class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if (left <= right) ans.push_back({left, right});  // ȡ����
            // �Ҷ˴������
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
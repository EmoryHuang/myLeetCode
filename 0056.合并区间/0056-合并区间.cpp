/*
 * @Descroption: LeetCode 56. �ϲ�����
 * @Author: EmoryHuang
 * @Date: 2021-05-11 14:56:36
 * @����˼·: ���б��е����䰴����˵���������
 * �����ǰ�������˵�������ans�����һ��������Ҷ˵�֮����ô���ǲ����غϣ����ǿ���ֱ�ӽ���������������ans��ĩβ
 * �����غϣ��������� ans �����һ��������Ҷ˵㣬������Ϊ���ߵĽϴ�ֵ��
 */

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());  // ������С��������
        vector<vector<int>> ans;
        for (auto s : intervals) {
            int start = s[0], end = s[1];
            // ����ǵ�һ������������䲻�ص�
            if (!ans.size() || ans.back()[1] < start) {
                ans.push_back({start, end});              // ��¼����
            } else                                        // ����������ص�
                ans.back()[1] = max(ans.back()[1], end);  // ȡ���Ľ���λ��
        }
        return ans;
    }
};
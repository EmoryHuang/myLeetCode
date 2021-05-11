class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());  // ������С��������
        for (auto p : intervals) {
            int start = p[0], end = p[1];
            // ����ǵ�һ������������䲻�ص�
            if (!ans.size() || ans.back()[1] < start) {
                ans.push_back({start, end});              // ��¼����
            } else                                        // ����������ص�
                ans.back()[1] = max(ans.back()[1], end);  // ȡ���Ľ���λ��
        }
        return ans;
    }
};
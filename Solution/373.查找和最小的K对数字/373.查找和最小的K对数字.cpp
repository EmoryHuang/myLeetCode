/*
 * @Descroption: LeetCode 373. ���Һ���С��K������
 * @Author: EmoryHuang
 * @Date: 2021-08-24 15:51:57
 * @Method:
 * ά��һ������ѣ�����������Ԫ��֮��
 * �����е�Ԫ���������� k����ô����ǰԪ����Ѷ�Ԫ�رȽ�
 */

class Solution {
   public:
    typedef tuple<int, int, int> tiii;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<tiii> q;
        for (int i = 0; i < min(n1, k); i++)
            for (int j = 0; j < min(n2, k); j++)
                if (q.size() < k)
                    q.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                else if (get<0>(q.top()) > nums1[i] + nums2[j]) {
                    q.pop();
                    q.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                }
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto [_, u, v] = q.top();
            q.pop();
            ans.push_back({u, v});
        }
        return ans;
    }
};
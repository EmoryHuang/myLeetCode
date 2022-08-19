/*
 * @Descroption: LeetCode 373. 查找和最小的K对数字
 * @Author: EmoryHuang
 * @Date: 2021-08-24 15:51:57
 * @Method:
 * 维护一个大根堆，遍历数组存放元素之和
 * 若堆中的元素数量大于 k，那么将当前元素与堆顶元素比较
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
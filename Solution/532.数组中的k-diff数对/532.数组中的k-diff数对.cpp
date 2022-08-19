/*
 * @Descroption: LeetCode 532. �����е� k-diff ����
 * @Author: EmoryHuang
 * @Date: 2022-06-15 09:05:24
 * @Method:
 * ʹ�ù�ϣ���¼���ֵ�����
 * ���ڵ�ǰ���� num����� num - k �� num + k �ڹ�ϣ���У���Ϊ k-diff ����
 */

class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        set<int> vis, ans;
        for (int num : nums) {
            if (vis.find(num - k) != vis.end()) ans.insert(num - k);
            if (vis.find(num + k) != vis.end()) ans.insert(num);
            vis.insert(num);
        }
        return ans.size();
    }
};
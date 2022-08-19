/*
 * @Descroption: LeetCode 46. ȫ����
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:11:00
 * @����˼·:
 * ���ݷ����������п���
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> order;
    void dfs(vector<int>& nums, vector<bool>& vis) {
        if (order.size() == nums.size()) {
            ans.push_back(order);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {  // ���δ����
                vis[i] = true;
                order.push_back(nums[i]);
                dfs(nums, vis);
                vis[i] = false;  // ����ѡ��
                order.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        dfs(nums, vis);
        return ans;
    }
};
/*
 * @Descroption: LeetCode 47. ȫ���� II
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:16:00
 * @����˼·:
 * ���ݷ����������п���
 * �����[46.ȫ����]�ɰ����ظ����֣���ʵ����ֱ��ʹ��set��ȥȥ���鷳
 *
 * �����ʹ��set����ô����Ҫ���������ʱ���ظ����ֽ����ж�
 */

class Solution {
   public:
    // ����һ��set
    // set<vector<int>> st;
    // vector<int> order;
    // void dfs(vector<int>& nums, vector<bool>& vis) {
    //     if (order.size() == nums.size()) {
    //         st.insert(order);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (!vis[i]) {  // ���δ����
    //             vis[i] = true;
    //             order.push_back(nums[i]);
    //             dfs(nums, vis);
    //             vis[i] = false;  // ����ѡ��
    //             order.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     vector<bool> vis(nums.size(), false);
    //     dfs(nums, vis);
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }

    // ������
    vector<vector<int>> ans;
    vector<int> order;
    void dfs(vector<int>& nums, vector<bool>& vis) {
        if (order.size() == nums.size()) {
            ans.push_back(order);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {  // ���δ����
                // �����ǰһ���ѷ��ʵ�������ͬ
                if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1]) continue;
                vis[i] = true;
                order.push_back(nums[i]);
                dfs(nums, vis);
                vis[i] = false;  // ����ѡ��
                order.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, vis);
        return ans;
    }
};
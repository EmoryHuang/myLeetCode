/*
 * @Descroption: ��ָ Offer II 083. û���ظ�Ԫ�ؼ��ϵ�ȫ����
 * @Author: EmoryHuang
 * @Date: 2021-08-06 16:50:05
 * @Method:
 * �򵥻���
 * ����û���ظ�Ԫ�أ���˿���ֱ���ж�Ԫ���Ƿ���������
 * ��ȻҲ����ʹ�ö���ռ��¼Ԫ���Ƿ�ʹ��
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
    void dfs(vector<int> nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size());
        dfs(nums);
        return ans;
    }
};
/*
 * @Descroption: LeetCode 39. ����ܺ�
 * @Author: EmoryHuang
 * @Date: 2021-05-27 21:33:17
 * @����˼·:
 * �ݹ�+����
 * ͨ���ݹ�Ѱ�����к�Ϊtarget�����
 * Ϊ�˱����ظ���ϣ���Ҫ�ȶ�candidates��������
 * ��֦���� num С�ڵ�ǰ��ϵ����һ���� comb.back() >= num�����ܼ���
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(vector<int>& candidates, int target) {
        if (target == 0) ans.push_back(comb);
        if (target < 0) return;
        for (int num : candidates) {
            if (comb.size() == 0 || comb.back() >= num) {
                comb.push_back(num);
                dfs(candidates, target - num);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target);
        return ans;
    }
};
/*
 * @Descroption: LeetCode 40. ����ܺ� II
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:34:17
 * @����˼·:
 * ���ݼ�֦
 * ��[39. ����ܺ�]���ƣ�������ÿ��������ÿ�������ֻ��ʹ��һ��
 *
 * ����Ĺؼ�����ȥ�أ��������Ĺ������ж��Ƿ������ظ������
 * ������˵�������ǵ�һ��ѭ�������ҵ�ǰԪ�ص���ǰһ��Ԫ��ʱ������
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(vector<int> candidates, int target, int ind) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        if (target < 0) return;
        for (int i = ind; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                // �����ǵ�һ��ѭ�������ҵ�ǰԪ�ص���ǰһ��Ԫ��ʱ������
                if (i > ind && candidates[i] == candidates[i - 1]) continue;
                comb.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
/*
 * @Descroption: LeetCode 1743. ������Ԫ�ضԻ�ԭ����
 * @Author: EmoryHuang
 * @Date: 2021-07-25 13:38:33
 * @����˼·:
 * ʹ�ù�ϣ��洢����Ԫ��
 * ���У���βԪ��ֻ�����һ�Σ���ˣ�ֻ��Ҫ���ҳ���βԪ��
 * Ȼ��������Ԫ��Ѱ�Ҽ���
 */

class Solution {
   public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> hash;
        for (auto pair : adjacentPairs) {
            hash[pair[0]].push_back(pair[1]);
            hash[pair[1]].push_back(pair[0]);
        }
        vector<int> ans;
        int n = adjacentPairs.size() + 1;
        for (auto [key, value] : hash) {
            // ��βԪ��ֻ����һ��
            if (value.size() == 1) {
                // ������Ԫ�غ����ڵ�Ԫ��
                ans.push_back(key);
                ans.push_back(value[0]);
                break;
            }
        }
        for (int i = 2; i < n; i++) {
            // ��һ��Ԫ�ص�����Ԫ��
            auto next = hash[ans[i - 1]];
            ans.push_back(next[0] == ans[i - 2] ? next[1] : next[0]);
        }
        return ans;
    }
};
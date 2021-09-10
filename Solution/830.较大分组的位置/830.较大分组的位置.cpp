/*
 * @Descroption: LeetCode 830. �ϴ�����λ��
 * @Author: EmoryHuang
 * @Date: 2021-06-19 15:41:00
 * @����˼·:
 * һ�α��������м���
 * �����ǰ�ַ����һ���ַ���ͬ���ҷ��鳤�ȴﵽ 3�������
 */

class Solution {
   public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                if (cnt >= 3) ans.push_back({i - cnt + 1, i});
                cnt = 1;
            } else
                cnt += 1;
        }
        return ans;
    }
};
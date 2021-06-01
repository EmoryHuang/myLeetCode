/*
 * @Descroption: LeetCode 1744. ����������ϲ��������Ե�����ϲ�����ǹ���
 * @Author: EmoryHuang
 * @Date: 2021-06-01 19:57:00
 * @����˼·:
 * ����ǹ�������ǰ׺��
 * �ɴ˿��Եõ��� i ���ǹ���ŷ�ΧΪ [pre[i]+1, pre[i] + candiesCount[i]]
 * ����һ���棬ÿ�����ٳ� 1 ���ǹ�������� Capi ���ǹ�
 * ��˳Ե��ǹ��������������� [dayi + 1, (dayi + 1) * Capi]
 * ֻҪ�ж������������Ƿ��н�������
 */

class Solution {
   public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> pre(n + 1);
        vector<bool> ans;
        // ����ǰ׺��
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + candiesCount[i];
        for (auto query : queries) {
            long long cap = query[2];
            long long minCandy = query[1] + 1;  // ��ϲ�������������ܳԵ�������
            long long maxCandy = (query[1] + 1) * cap;  // ��ϲ�������������ܳԵ�������
            long long firstCandy = pre[query[0]] + 1;   // ��һ��ϲ�����ǹ�
            long long lastCandy = pre[query[0]] + candiesCount[query[0]];  // ���һ��ϲ�����ǹ�
            ans.push_back(lastCandy >= minCandy && firstCandy <= maxCandy);
        }
        return ans;
    }
};
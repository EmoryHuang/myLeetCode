/*
 * @Descroption: LeetCode 638. �����
 * @Author: EmoryHuang
 * @Date: 2021-10-24 18:59:58
 * @Method:
 * dfs ���仯
 * ʹ�� cache ��¼���ֵ�������
 * ���ȿ����ڵ�ǰ�����²����������Ļ��ѣ�Ȼ�����ÿ����������ж��Ƿ��������
 * ���ڷ���Ҫ��Ĵ��������������
 * Ȼ��ݹ����ⲻͬ�����µ���С����
 */

class Solution {
   public:
    map<vector<int>, int> _cache;
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& cur) {
        // ������ֹ������⣬ֱ�ӷ���
        if (_cache[cur]) return _cache[cur];
        int ans = 0;
        // ����������
        for (int i = 0; i < cur.size(); i++) ans += cur[i] * price[i];
        // ����ÿ�����
        for (int i = 0; i < special.size(); i++) {
            vector<int> nxt = cur;
            bool flag = true;
            for (int j = 0; j < price.size(); j++) {
                // ���������Ʒ���������ܳ���������
                if (special[i][j] > cur[j]) {
                    flag = false;
                    break;
                }
            }
            // ��ǰ���������������
            if (!flag) continue;
            // ����������
            for (int j = 0; j < price.size(); j++) nxt[j] -= special[i][j];
            ans = min(ans, dfs(price, special, nxt) + special[i].back());
        }
        _cache[cur] = ans;
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};
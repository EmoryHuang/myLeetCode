/*
 * @Descroption: LeetCode 646. �������
 * @Author: EmoryHuang
 * @Date: 2021-06-14 13:36:00
 * @����˼·:
 * ����һ��̰��˼�룬
 * �����Եĵڶ���ֵ��С��������
 * Ȼ��Ƚ� pairs[i][0] �� pre �Ĵ�С
 *
 * ����������̬�滮
 * dp[i]��ʾ�� pairs[i] ��β������ĳ���
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    // ����һ��̰��
    // static bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     sort(pairs.begin(), pairs.end(), cmp);
    //     int ans = 1, pre = pairs[0][1];
    //     for (int i = 1; i < pairs.size(); i++) {
    //         if (pairs[i][0] > pre) {
    //             ans++;
    //             pre = pairs[i][1];
    //         }
    //     }
    //     return ans;
    // }

    // ����������̬�滮
    static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        // dp[i]��ʾ�� pairs[i] ��β������ĳ���
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
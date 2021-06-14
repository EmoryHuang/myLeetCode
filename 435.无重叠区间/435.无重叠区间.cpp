/*
 * @Descroption: LeetCode 435. ���ص�����
 * @Author: EmoryHuang
 * @Date: 2021-06-14 14:12:00
 * @����˼·:
 * ����һ��̰��˼�룬
 * �����Եĵڶ���ֵ��С��������
 * Ȼ��Ƚ� intervals[i][0] �� pre �Ĵ�С
 *
 * ����������̬�滮
 * dp[i]��ʾ�� intervals[i] ��β������ĳ���
 * ״̬ת�Ʒ��̣�dp[i] = max(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    // ����һ��̰��
    static bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, pre = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < pre) {
                ans++;
                continue;
            }
            pre = intervals[i][1];
        }
        return ans;
    }

    // ����������̬�滮
    // static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(), cmp);
    //     int n = intervals.size();
    //     // dp[i]��ʾ�� intervals[i] ��β������ĳ���
    //     vector<int> dp(n, 1);
    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (intervals[i][0] >= intervals[j][1]) dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    //     return n - *max_element(dp.begin(), dp.end());
    // }
};
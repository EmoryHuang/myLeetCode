/*
 * @Descroption: LeetCode 1024. ��Ƶƴ��
 * @Author: EmoryHuang
 * @Date: 2021-10-20 20:34:25
 * @Method:
 * ����һ����̬�滮
 * dp[i] ��ʾ������ [0, i) ������Ҫ����С����
 * ״̬ת�Ʒ��̣�dp[i] = min(dp[i], dp[l] + 1)
 *
 * ��������̰��
 * ʹ�� maxr[i] ��ʾ��˵� i ���ܹ����������λ��
 * ̰�ı���ÿ��λ�ã����ﵱǰλ���ܹ��ﵽ����Զλ��
 */

class Solution {
   public:
    // ����һ����̬�滮
    // int videoStitching(vector<vector<int>>& clips, int time) {
    //     // dp[i] ��ʾ������ [0, i) ������Ҫ����С����
    //     vector<int> dp(time + 1, 0x3f3f3f3f);
    //     dp[0] = 0;
    //     for (int i = 1; i <= time; i++) {
    //         for (auto clip : clips) {
    //             int l = clip[0], r = clip[1];
    //             if (i > l && i <= r) dp[i] = min(dp[i], dp[l] + 1);
    //         }
    //     }
    //     return dp[time] == 0x3f3f3f3f ? -1 : dp[time];
    // }

    // ��������̰��
    int videoStitching(vector<vector<int>>& clips, int time) {
        // maxr[i] ��ʾ��˵� i ���ܹ����������λ��
        vector<int> maxr(time, 0);
        int ans = 0, last = 0, pre = 0;
        for (auto clip : clips) {
            int l = clip[0], r = clip[1];
            if (l < time) maxr[l] = max(maxr[l], r);
        }
        // ����ÿ��λ��
        for (int i = 0; i < time; i++) {
            last = max(last, maxr[i]);
            if (i == last) return -1;  // ��һ��λ���޷�������
            if (i == pre) {
                // ��������һ��λ��
                pre = last;
                ans++;
            }
        }
        return ans;
    }
};
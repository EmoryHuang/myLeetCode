/*
 * @Descroption: LeetCode 781. ɭ���е�����
 * @Author: EmoryHuang
 * @Date: 2021-04-04 19:36:36
 * @����˼·:
 * ĳ����ɫ������ `m` ֻ�����ǻش�Ĵ���ֵΪ `k` ������ `m = k + 1`
 * ͨ��ģ�⣬�ȶ� `answers` ��������Ȼ��������Ե�ǰԪ�� `k` ����� `k` �� `k` ֵ���к���
 */

class Solution {
   public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int len = answers.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += answers[i] + 1;
            int k = answers[i];
            // ���Ե�ǰԪ�� k ����� k �� k ֵ
            while (k-- && i + 1 < len && answers[i] == answers[i + 1]) i++;
        }
        return ans;
    }
};
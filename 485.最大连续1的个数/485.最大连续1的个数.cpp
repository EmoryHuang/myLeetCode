/*
 * @Descroption: LeetCode 485. ������� 1 �ĸ���
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:52:36
 * @����˼·:
 * ���⣬����һ�鲢��¼������� 1 �ĸ�������
 */

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int num : nums) {
            if (num == 1) {
                cnt++;
                ans = max(ans, cnt);
            } else
                cnt = 0;
        }
        return ans;
    }
};
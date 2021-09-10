/*
 * @Descroption: LeetCode 376. �ڶ�����
 * @Author: EmoryHuang
 * @Date: 2021-04-23 15:35:36
 * @����˼·:
 * ��������֮�󣬷���ֻ��Ҫͳ�Ƹ������С��塹�롸�ȡ����������ɣ�������Ҫ���ǡ�����Ԫ�ء�
 * ������Ҫͨ����̬�滮���ǲ�ͬ�����
 */

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;  // �ڶ�����
        int ans = 1;
        for (int i = 1; i < len; i++) {
            // ǰһ����ͺ�һ������������
            if ((flag >= 0 && nums[i] - nums[i - 1] < 0) ||
                (flag <= 0 && nums[i] - nums[i - 1] > 0)) {
                flag = nums[i] - nums[i - 1];
                ans++;
            }
        }
        return ans;
    }
};
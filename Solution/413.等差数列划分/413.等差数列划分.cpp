/*
 * @Descroption: LeetCode 413. �Ȳ����л���
 * @Author: EmoryHuang
 * @Date: 2021-08-10 13:10:26
 * @Method:
 * ��̬�滮
 * ������nums[i]��β�ĵȲ����еĸ���
 */


class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        // ������nums[i]��β�ĵȲ����еĸ���
        for (int i = 2; i < n; i++)
            if (nums[i] + nums[i - 2] == 2 * nums[i - 1]) {
                ans += ++cnt;
            } else
                cnt = 0;
        return ans;
    }
};
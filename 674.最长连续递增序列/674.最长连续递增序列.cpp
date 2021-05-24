/*
 * @Descroption: LeetCode 674. �������������
 * @Author: EmoryHuang
 * @Date: 2021-05-24 20:33:11
 * @����˼·:
 * ̰��˼�룬��nums[i] < nums[i + 1]����count++���������¼���
 */

class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int ans = 1, count = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1])
                count++;
            else
                count = 1;
            ans = max(ans, count);
        }
        return ans;
    }
};
/*
 * @Descroption: LeetCode 561. ������ I
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:29:56
 * @����˼·:
 * ���ȶ������������
 * Ȼ������λ��������Ӽ���
 */

class Solution {
   public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2) ans += nums[i];
        return ans;
    }
};
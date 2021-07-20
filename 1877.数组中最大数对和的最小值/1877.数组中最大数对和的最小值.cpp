/*
 * @Descroption: LeetCode 1877. ������������Ժ͵���Сֵ
 * @Author: EmoryHuang
 * @Date: 2021-07-20 19:16:20
 * @����˼·:
 * ���� + ����
 * ��Ϊ��ĿҪ��������Ժ���С����ô�Ϳ���������Ȼ����βԪ���������
 * ���ȡ���ֵ
 */

class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) ans = max(ans, nums[i] + nums[n - i - 1]);
        return ans;
    }
};
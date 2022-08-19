/*
 * @Descroption: LeetCode 152. �˻����������
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:00:48
 * @����˼·:
 * ��������ʱ���㵱ǰ���ֵ�����ϸ���
 * ���ڴ��ڸ�������ô�ᵼ�����ı���С�ģ���С�ı����ġ���˻���Ҫά����ǰ��Сֵ
 */

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int dpmax, dpmin, ans;
        dpmax = dpmin = ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpmax = dpmax, tmpmin = dpmin;
            dpmax = max(nums[i], max(nums[i] * tmpmax, nums[i] * tmpmin));
            dpmin = min(nums[i], min(nums[i] * tmpmax, nums[i] * tmpmin));
            ans = max(ans, dpmax);
        }
        return ans;
    }
};
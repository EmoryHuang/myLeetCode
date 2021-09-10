/*
 * @Descroption: LeetCode 1365. �ж���С�ڵ�ǰ���ֵ�����
 * @Author: EmoryHuang
 * @Date: 2021-06-22 19:52:00
 * @����˼·:
 * cnt[i] ��ʾ���� i ���ֵĴ�����
 * ��ô�������� i ���ԣ�С��������Ŀ��Ϊ cnt[0...i-1] ���ܺ�
 */

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(101);
        for (int num : nums) cnt[num]++;
        for (int i = 1; i <= 100; i++) cnt[i] += cnt[i - 1];
        vector<int> ans;
        for (int i = 0; i < n; i++) ans.push_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
        return ans;
    }
};
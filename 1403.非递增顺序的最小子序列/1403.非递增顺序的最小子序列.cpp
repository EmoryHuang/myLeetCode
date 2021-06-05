/*
 * @Descroption: LeetCode 1403. �ǵ���˳�����С������
 * @Author: EmoryHuang
 * @Date: 2021-06-05 14:59:00
 * @����˼·:
 * ̰��˼�룬���Ƚ� nums ��������
 * Ȼ��Ӵ�Сѡ��Ԫ�أ������������е�Ԫ��֮�ʹ���ʣ��Ԫ�أ����ҵ�
 */

class Solution {
   public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, subsum = 0;
        for (int num : nums) sum += num;
        vector<int> sub;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sub.push_back(nums[i]);
            subsum += nums[i];
            if (subsum > sum - subsum) return sub;
        }
        return sub;
    }
};
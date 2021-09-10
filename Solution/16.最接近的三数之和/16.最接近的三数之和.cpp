/*
 * @Descroption: LeetCode 16. ��ӽ�������֮��
 * @Author: EmoryHuang
 * @Date: 2021-03-21 14:05:36
 * @����˼·: ��ǰһ�� ����֮�� ���Ƶķ�����������Ȼ��������ڲ�ʹ��˫ָ��
 */

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int min = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int j = i + 1, k = len - 1;
            while (j < k) {
                int sum = nums[j] + nums[k] + nums[i];
                if (fabs(min - target) > fabs(sum - target)) {
                    min = sum;
                }
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return target;
            }
        }
        return min;
    }
};
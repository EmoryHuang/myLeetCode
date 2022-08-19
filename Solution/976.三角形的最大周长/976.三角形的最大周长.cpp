/*
 * @Descroption: LeetCode 976. �����ε�����ܳ�
 * @Author: EmoryHuang
 * @Date: 2021-07-10 15:23:04
 * @����˼·:
 * �����Ӻ���ǰ�������飬����������������������Σ���Ϊ����ܳ�
 */

class Solution {
   public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // �����Ӻ���ǰ��������
        for (int i = nums.size() - 1; i >= 2; i--)
            // �����������������������
            if (nums[i] < nums[i - 1] + nums[i - 2]) 
                return nums[i] + nums[i - 1] + nums[i - 2];
        return 0;
    }
};
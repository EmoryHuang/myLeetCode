/*
 * @Descroption: LeetCode 1. ����֮��
 * @Author: EmoryHuang
 * @Date: 2021-03-15 19:20:36
 * @����˼·: ���⣬ֱ�ӱ�������Ԫ�أ�������Ԫ��֮����ȣ��򷵻��±�
 */

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
            for (int j = i + 1; j < len; j++)
                if (nums[i] + nums[j] == target) return {i, j};
        return {};
    }
};
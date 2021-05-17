/*
 * @Descroption: LeetCode 283. �ƶ���
 * @Author: EmoryHuang
 * @Date: 2021-05-17 16:42:26
 * @����˼·:
 * ˫ָ�룬i�������飬j��¼��0���鳤��
 * ���nums[i]��Ϊ 0 �򽻻�
 */
 
class Solution {
   public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int i = 0, j = 0;  // i�������飬j��¼��0���鳤��
        while (i < nums.size()) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);  // �����Ϊ0�򽻻�
                j++;
            }
            i++;
        }
    }
};
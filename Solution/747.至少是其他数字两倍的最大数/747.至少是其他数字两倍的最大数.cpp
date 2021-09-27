/*
 * @Descroption: LeetCode 747. �������������������������
 * @Author: EmoryHuang
 * @Date: 2021-09-27 19:56:49
 * @Method:
 * ����
 * ����һ�����飬�ҳ����ֵ�ʹδ�ֵ
 */

class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int a = 0, b = 0, pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
                pos = i;
            } else if (nums[i] > b)
                b = nums[i];
        }
        return a >= 2 * b ? pos : -1;
    }
};
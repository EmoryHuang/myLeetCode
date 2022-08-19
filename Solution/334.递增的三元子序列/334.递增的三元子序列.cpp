/*
 * @Descroption: LeetCode 334. ��������Ԫ������
 * @Author: EmoryHuang
 * @Date: 2021-07-27 19:26:17
 * @Method:
 * ���������������
 * ά����Сֵ���м�ֵ�����ҵ����м�ֵ�����Ԫ�أ����ҵ�����Ԫ������
 */

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, mid = INT_MAX;
        for (int num : nums) {
            if (min >= num)
                min = num;
            else if (mid >= num)
                mid = num;
            else
                return true;
        }
        return false;
    }
};
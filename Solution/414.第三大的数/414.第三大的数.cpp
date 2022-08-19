/*
 * @Descroption: LeetCode 414. ���������
 * @Author: EmoryHuang
 * @Date: 2021-10-06 14:32:58
 * @Method:
 * ����һ�λ�ȡ���ֵ���δ�ֵ��������ֵ
 * ������һ�������ֵ����ֱ��ֵ���д���
 */

class Solution {
   public:
    int thirdMax(vector<int>& nums) {
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (int num : nums) {
            if (num == a || num == b || num == c) continue;
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (num > b) {
                c = b;
                b = num;
            } else if (num > c) {
                c = num;
            }
        }
        return c != LONG_MIN ? c : a;
    }
};
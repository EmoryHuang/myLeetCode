/*
 * @Descroption: LeetCode 724. Ѱ������������±�
 * @Author: EmoryHuang
 * @Date: 2021-06-16 14:34:00
 * @����˼·:
 * ���⣬�������飬��ȥ����ǰԪ�غ�ǰ�벿�ֺ�Ϊ����Ԫ�ص�һ���򷵻��±�
 */

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, cur = 0;
        for (int num : nums) sum += num;
        for (int i = 0; i < nums.size(); i++) {
            if (2 * cur + nums[i] == sum) return i;
            cur += nums[i];
        }
        return -1;
    }
};
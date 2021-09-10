/*
 * @Descroption: LeetCode 1437. �Ƿ����� 1 ��������� k ��Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-06-05 16:04:00
 * @����˼·:
 * �������飬��¼�������� 1 ֮��ľ��룬��С�� k �򷵻� false
 */

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -1;  // ǰһ��1��λ��
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (pre != -1 && (i - pre - 1) < k) return false;
                pre = i;
            }
        }
        return true;
    }
};
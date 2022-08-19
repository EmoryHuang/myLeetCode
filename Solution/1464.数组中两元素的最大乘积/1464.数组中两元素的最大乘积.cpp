/*
 * @Descroption: LeetCode 1464. ��������Ԫ�ص����˻�
 * @Author: EmoryHuang
 * @Date: 2021-09-15 15:36:03
 * @Method:
 * ��������
 * һ�α����õ����ֵ�ʹδ�ֵ
 */

class Solution {
   public:
    // ��������
    // int maxProduct(vector<int>& nums) {
    //     int n = nums.size(), ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
    //         }
    //     }
    //     return ans;
    // }

    // һ�α���
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for (int num : nums) {
            if (num > max2) max2 = num;
            if (max2 > max1) swap(max1, max2);
        }
        return (max1 - 1) * (max2 - 1);
    }
};
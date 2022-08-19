/*
 * @Descroption: ��ָ Offer 21. ��������˳��ʹ����λ��ż��ǰ��
 * @Author: EmoryHuang
 * @Date: 2021-06-30 20:46:00
 * @����˼·:
 * ά������ָ��
 * ����һ������ָ��
 * fast ��������Ԫ�أ�slow ��¼����λ��
 * ��������ͷβָ��
 */

class Solution {
   public:
    // ������������ָ��
    vector<int> exchange(vector<int>& nums) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {  // ���������
                swap(nums[fast], nums[slow]);
                slow++;
            }
            fast++;
        }
        return nums;
    }

    // ��������ͷβָ��
    // vector<int> exchange(vector<int>& nums) {
    //     int l = 0, r = nums.size() - 1;
    //     while (l < r) {
    //         while (l < r && nums[l] % 2 == 1) l++;
    //         while (l < r && nums[r] % 2 == 0) r--;
    //         swap(nums[l], nums[r]);
    //         l++, r--;
    //     }
    //     return nums;
    // }
};
/*
 * @Descroption: LeetCode 189. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-03-24 19:32:36
 * @����˼·: �ʼ���� O(kn)�ı����������ֳ�ʱ��ͨ�� reverse()��Ч�ʻ���ͦ�ߵ�
 */

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums.begin(), nums.end());        // ��ת��������
        reverse(nums.begin(), nums.begin() + k);  // ��תǰk��
        reverse(nums.begin() + k, nums.end());    // ��ת��k��
    }
};
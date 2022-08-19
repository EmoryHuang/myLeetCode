/*
 * @Descroption: ��ָ Offer 39. �����г��ִ�������һ�������
 * @Author: EmoryHuang
 * @Date: 2021-07-03 15:28:53
 * @����˼·:
 * ����һ�������ȡ��λ��
 * �������ֵĳ��ִ�������һ�룬�����λ��һ���������
 * ����������ϣ��
 */

class Solution {
   public:
    // ����һ�������ȡ��λ��
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // ����������ϣ��
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> mp;
    //     for (int num : nums)
    //         if (mp[num]++ > nums.size()) return num;
    //     return 0;
    // }
};
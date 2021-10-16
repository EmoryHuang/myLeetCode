/*
 * @Descroption: LeetCode 2032. ���������������г��ֵ�ֵ
 * @Author: EmoryHuang
 * @Date: 2021-10-16 19:23:42
 * @Method:
 * ��ϣ��
 * ʹ�ù�ϣ���¼3�����������ֳ��ֵ������������ִ������� 2 �ļ��� ans
 */

class Solution {
   public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> cnt1(nums1.begin(), nums1.end());
        set<int> cnt2(nums2.begin(), nums2.end());
        set<int> cnt3(nums3.begin(), nums3.end());
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int num : cnt1) hash[num]++;
        for (int num : cnt2) hash[num]++;
        for (int num : cnt3) hash[num]++;
        for (auto p : hash)
            if (p.second >= 2) ans.push_back(p.first);
        return ans;
    }
};
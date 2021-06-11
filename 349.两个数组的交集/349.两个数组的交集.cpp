/*
 * @Descroption: LeetCode 349. ��������Ľ���
 * @Author: EmoryHuang
 * @Date: 2021-06-11 16:30:00
 * @����˼·:
 * ����һ��ʹ�÷�װ����
 *
 * ������������ + ˫ָ��
 * ������Ȼ��ʹ��˫ָ��������飬��Ԫ����ͬ����뼯��
 * ���򽫽�Сһ����ָ�����
 */

class Solution {
   public:
    // ����һ��ʹ�÷�װ����
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (s1.find(num) != s1.end()) ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }

    // ������������ + ˫ָ��
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());
    //     unordered_set<int> unit;
    //     int i = 0, j = 0;
    //     while (i < nums1.size() && j < nums2.size()) {
    //         if (nums1[i] == nums2[j]) {
    //             unit.insert(nums1[i]);
    //             i++;
    //             j++;
    //         } else if (nums1[i] > nums2[j])
    //             j++;
    //         else
    //             i++;
    //     }
    //     vector<int> ans(unit.begin(), unit.end());
    //     return ans;
    // }
};
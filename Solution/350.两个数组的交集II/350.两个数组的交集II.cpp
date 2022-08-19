/*
 * @Descroption: LeetCode 350. ��������Ľ��� II
 * @Author: EmoryHuang
 * @Date: 2021-06-11 16:51:00
 * @����˼·:
 * ��ǰһ�ⲻͬ���ǣ��������ظ�Ԫ��
 * ���� + ˫ָ��
 * ������Ȼ��ʹ��˫ָ��������飬��Ԫ����ͬ����뼯��
 * ���򽫽�Сһ����ָ�����
 */

class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> unit;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                unit.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return unit;
    }
};
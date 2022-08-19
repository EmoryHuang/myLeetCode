/*
 * @Descroption: LeetCode 88. �ϲ�������������
 * @Author: EmoryHuang
 * @Date: 2021-03-24 16:14:36
 * @����˼·:
 * ��ʡ�µķ������ϲ�Ȼ�� sort()
 *
 * ���������˫ָ�루����������������飬ѡ���С��һ�������µ����飩���ԣ�
 * ����˫ָ����ŵ����ڲ���Ҫ����ռ�
 */

class Solution {
   public:
    // ����һ���ϲ�sort()
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     for (int i = 0; i < n; i++) nums1[m + i] = nums2[i];
    //     sort(nums1.begin(), nums1.end());
    // }

    // ������������˫ָ��
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int tail = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[tail--] = nums1[i--];
            else
                nums1[tail--] = nums2[j--];
        }
        while (j >= 0) nums1[tail--] = nums2[j--];  // ������ʣ��
    }
};